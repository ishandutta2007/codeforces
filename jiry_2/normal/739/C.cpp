#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=310000;
int Lans[N<<2],Rans[N<<2],ans[N<<2],si[N<<2],Lf[N<<2],Rf[N<<2];
long long A[N<<2],L[N<<2],R[N<<2];
int n,m;
void change(int k1){
	int l=k1*2,r=k1*2+1;
	ans[k1]=max(ans[l],ans[r]);
	L[k1]=L[l]; R[k1]=R[r];
	if (R[l]>L[r]) ans[k1]=max(ans[k1],Rf[l]+Lans[r]);
	if (L[r]>R[l]) ans[k1]=max(ans[k1],Lf[r]+Rans[l]);
	Rans[k1]=Rans[r]; Lans[k1]=Lans[l];
	if (Rans[r]==si[r]&&R[l]<L[r]) Rans[k1]+=Rans[l];
	if (Lans[l]==si[l]&&R[l]>L[r]) Lans[k1]+=Lans[r];
	Rf[k1]=Rf[r]; Lf[k1]=Lf[l];
	if (Rf[r]==si[r]&&R[l]<L[r]) Rf[k1]+=Rans[l];
	if (Lans[r]==si[r]&&R[l]>L[r]) Rf[k1]+=Rf[l];
//	cout<<"asd "<<Lf[k1]<<" "<<R[l]<<" "<<L[r]<<" "<<si[r]<<" "<<Lf[l]<<" "<<Lans[r]<<endl;
	if (Lf[l]==si[l]&&R[l]>L[r]) Lf[k1]+=Lans[r];
	if (Rans[l]==si[l]&&R[l]<L[r]) Lf[k1]+=Lf[r]; 
}
void add(int k1,long long k2){
	A[k1]+=k2; L[k1]+=k2; R[k1]+=k2;
}
void pushdown(int k1){
	if (A[k1]!=0){
		add(k1*2,A[k1]); add(k1*2+1,A[k1]); A[k1]=0;
	}
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		add(k1,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	add(k1*2,k2,mid,k4,k5,k6);
	add(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
//	cout<<"fa "<<k2<<" "<<k3<<" "<<ans[k1]<<" "<<Lans[k1]<<" "<<Rans[k1]<<" "<<Lf[k1]<<" "<<Rf[k1]<<endl;
}
void buildtree(int k1,int k2,int k3){
	si[k1]=k3-k2+1;
	if (k2==k3){
		int w; scanf("%d",&w); L[k1]=R[k1]=w;
		Rans[k1]=Lans[k1]=ans[k1]=Lf[k1]=Rf[k1]=1;
		return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
int main(){
	scanf("%d",&n);
	buildtree(1,1,n);
	scanf("%d",&m);
	for (;m;m--){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		add(1,1,n,k1,k2,k3);
		printf("%d\n",ans[1]);
	}
	return 0;
}