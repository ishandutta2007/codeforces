#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200010;
vector<int>B[N],C[N];
long long sum[N<<2];
int mi[N<<2],se[N<<2],A[N<<2],t[N<<2],n,x[N],m,R[N],L[N],where[N],f[N],len;
void add(int k1,int k2){
	A[k1]+=k2; mi[k1]+=k2; sum[k1]+=1ll*t[k1]*k2;
}
void pushdown(int k1){
	if (A[k1]){
		int l=k1<<1,r=l+1;
		if (mi[l]==mi[r]){
			add(l,A[k1]); add(r,A[k1]);
		} else if (mi[l]<mi[r]) add(l,A[k1]);
		else add(r,A[k1]);
		A[k1]=0;
	}
}
void change(int k1){
	int l=k1<<1,r=l+1; mi[k1]=min(mi[l],mi[r]); sum[k1]=sum[l]+sum[r];
	if (mi[l]==mi[r]){
		t[k1]=t[l]+t[r]; se[k1]=min(se[l],se[r]);
	} else if (mi[l]<mi[r]){
		t[k1]=t[l]; se[k1]=min(se[l],mi[r]);
	} else {
		t[k1]=t[r]; se[k1]=min(se[r],mi[l]);
	}
}
void buildtree(int k1,int k2,int k3){
	if (k2==k3){
		t[k1]=1; mi[k1]=R[k2]; sum[k1]=R[k2]; se[k1]=1e9; return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
void down(int k1,int k2,int k3,int k6){
	if (mi[k1]>=k6) return;
	if (se[k1]>k6){
		add(k1,k6-mi[k1]); return;
	}
	pushdown(k1); int mid=k2+k3>>1;
	down(k1*2,k2,mid,k6);
	down(k1*2+1,mid+1,k3,k6);
	change(k1);
}
void change(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		down(k1,k2,k3,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	change(k1*2,k2,mid,k4,k5,k6);
	change(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
long long find(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return sum[k1];
	int mid=k2+k3>>1; pushdown(k1);
	return find(k1*2,k2,mid,k4,k5)+find(k1*2+1,mid+1,k3,k4,k5);
}
void change(int k1,int k2,int k3,int k4){
	while (where[k4]<k2) k4++;
	if (where[k4]>=k3){
		down(k1,k2,k3,f[k4]); return;
	}
	pushdown(k1); int mid=k2+k3>>1;
	change(k1*2,k2,mid,k4);
	change(k1*2+1,mid+1,k3,k4);
	change(k1);
}
void insert(int k1){
	change(1,1,n,1,n,L[k1]);
//	cout<<"change "<<1<<" "<<n<<" "<<L[k1]<<endl;
	int pre=k1; len=0;
	for (int i=B[x[k1]].size()-1;i>=0;i--){
		int k2=B[x[k1]][i];
		int ans=C[k2][C[k2].size()-1];
		if (ans>pre){
			len++; where[len]=ans; f[len]=k2;
		}
	}
	change(1,1,n,1);
}
int main(){
	scanf("%d",&n); m=0;
	for (int i=1;i<=n;i++) scanf("%d",&x[i]),m=max(m,x[i]);
	for (int i=1;i<=m;i++)
		for (int j=i;j<=m;j+=i) B[j].push_back(i);
	for (int i=1;i<=n;i++)
		for (int j=0;j<B[x[i]].size();j++)
			C[B[x[i]][j]].push_back(i);
	R[n]=0;
	for (int i=n-1;i;i--){
		R[i]=R[i+1];
		for (int j=0;j<B[x[i]].size();j++){
			int k1=B[x[i]][j];
			if (C[k1][C[k1].size()-1]!=i) R[i]=max(R[i],k1);
		}
	}
	L[1]=0;
	for (int i=2;i<=n;i++){
		L[i]=L[i-1];
		for (int j=0;j<B[x[i]].size();j++){
			int k1=B[x[i]][j];
			if (C[k1][0]!=i) L[i]=max(L[i],k1);
		}
	}
//	for (int i=1;i<=n;i++) cout<<L[i]<<" "; cout<<endl;
//	for (int i=1;i<=n;i++) cout<<R[i]<<" "; cout<<endl;
	buildtree(1,1,n); //cout<<sum[1]<<endl;
	long long ans=0;
	for (int i=1;i<=n;i++){ 
	//	cout<<"ask "<<i+1<<" "<<n<<" "<<find(1,1,n,i+1,n)<<endl;
		ans+=find(1,1,n,i+1,n)+L[i-1];
		insert(i);
	//	cout<<"fa "<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}