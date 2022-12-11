#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200010;
int n,m,x[N],L[N<<2],A[N<<2][32],B[70],C[N<<2],y[N],a[N];
void update(int k1,int l,int r){
	int len=0; 
	for (int i=1;i<=L[l];i++) B[++len]=A[l][i];
	for (int i=1;i<=L[r];i++) B[++len]=A[r][i];
	int now=0;
	for (int i=30;i>=0;i--){
		int r=0;
		for (int j=now+1;j<=len;j++) if (B[j]&(1<<i)){
			r=j; break;
		}
		if (r==0) continue;
		now++; swap(B[now],B[r]);
		for (int j=now+1;j<=len;j++) if (B[j]&(1<<i)) B[j]^=B[now];
	}
	L[k1]=now; for (int i=1;i<=now;i++) A[k1][i]=B[i];
}
void buildtree(int k1,int k2,int k3){
	if (k2==k3){
		if (y[k2]==0) return;
		A[k1][1]=y[k2]; L[k1]=1; return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	update(k1,k1*2,k1*2+1);
//	cout<<"fa "<<k2<<" "<<k3<<" "<<L[k1]<<endl;
//	for (int i=1;i<=L[k1];i++) cout<<A[k1][i]<<" "; cout<<endl;
}
void change(int k1,int k2,int k3,int k4,int k5){
	if (k2==k3){
		A[k1][1]^=k5; if (A[k1][1]==0) L[k1]=0; else L[k1]=1; return;
	}
	int mid=k2+k3>>1;
	if (mid>=k4) change(k1*2,k2,mid,k4,k5);
	else change(k1*2+1,mid+1,k3,k4,k5);
	update(k1,k1*2,k1*2+1);
}
void getans(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		update(0,0,k1); 
		
	//	cout<<"merge "<<k2<<" "<<k3<<endl;
	//	for (int i=1;i<=L[0];i++) cout<<A[0][i]<<" "; cout<<endl;
		return;
	}
	int mid=k2+k3>>1;
	getans(k1*2,k2,mid,k4,k5);
	getans(k1*2+1,mid+1,k3,k4,k5);
}
void add(int k1,int k2){
	for (;k1<=n;k1+=k1&(-k1)) a[k1]^=k2;
}
int find(int k1){
	int ans=0; for (;k1;k1-=k1&(-k1)) ans^=a[k1]; return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<n;i++) y[i]=x[i]^x[i+1];
	if (n>1)buildtree(1,1,n-1);
	for (;m;m--){
		int k1; scanf("%d",&k1);
		if (k1==1){
			int l,r,k; scanf("%d%d%d",&l,&r,&k);
			add(l,k); add(r+1,k);
			if (l>1) change(1,1,n-1,l-1,k);
			if (r<n) change(1,1,n-1,r,k);
		} else if (k1==2){
			L[0]=0; int l,r; scanf("%d%d",&l,&r); 
			A[0][1]=find(l)^x[l]; if (A[0][1]) L[0]++;// cout<<A[0][1]<<endl;
			if (n>1)getans(1,1,n-1,l,r-1);
		//	for (int i=1;i<=L[0];i++) cout<<A[0][i]<<" "; cout<<endl;
			printf("%d\n",(1<<L[0]));
		}
	}
	return 0;
}