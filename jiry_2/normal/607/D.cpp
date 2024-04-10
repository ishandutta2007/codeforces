#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mo=1e9+7;
struct ask{
	int pd,where;
}q[210000];
struct bian{
	int next,point;
}b[410000];
int p[210000],len,n,m,w[210000],dfs[210000],r[210000],sign,father[210000],d[210000];
const int N=210000;
int num[N<<2],A[N<<2],f[N<<2];
void add(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void dfs1(int k1){
	dfs[k1]=++sign;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		dfs1(j);
	}
	r[k1]=sign;
}
void chen(int k1,int k2){
	//cout<<"chen "<<k1<<" "<<k2<<endl;
	f[k1]=1ll*f[k1]*k2%mo; A[k1]=1ll*A[k1]*k2%mo; num[k1]=1ll*num[k1]*k2%mo;
}
void pushdown(int k1){
	if (A[k1]!=1){
		chen(k1*2,A[k1]); chen(k1*2+1,A[k1]); A[k1]=1;
	}
}
void change(int k1){
	num[k1]=(num[k1*2]+num[k1*2+1])%mo;
}
void chen(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		chen(k1,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	chen(k1*2,k2,mid,k4,k5,k6);
	chen(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void change(int k1,int k2,int k3,int k4,int k5){
	if (k2==k3){
		num[k1]=1ll*f[k1]*k5%mo; return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	if (mid>=k4) change(k1*2,k2,mid,k4,k5); else change(k1*2+1,mid+1,k3,k4,k5);
	change(k1);
}
void buildtree(int k1,int k2,int k3){
	f[k1]=1; A[k1]=1; if (k2==k3) return;
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
}
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
void insert(int k1){
	int k2=1ll*(d[father[k1]]+2)*quick(d[father[k1]]+1,mo-2)%mo;
	chen(1,1,n,dfs[father[k1]],r[father[k1]],k2); d[father[k1]]++;
	change(1,1,n,dfs[k1],w[k1]);
}
int find(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return num[k1];
	int mid=k2+k3>>1; pushdown(k1);
	return (find(k1*2,k2,mid,k4,k5)+find(k1*2+1,mid+1,k3,k4,k5))%mo;
}
int getw(int k1,int k2,int k3,int k4){
	if (k2==k3) return f[k1];
	int mid=k2+k3>>1; pushdown(k1);
	if (mid>=k4) return getw(k1*2,k2,mid,k4); else return getw(k1*2+1,mid+1,k3,k4);
}
int solve(int k1){
	int ans=1ll*find(1,1,n,dfs[k1],r[k1]);// cout<<ans<<endl;
	if (k1==1) return ans;
	ans=1ll*ans*quick(getw(1,1,n,dfs[father[k1]]),mo-2)%mo;
	return ans;
}
int main(){
	scanf("%d%d",&w[1],&m); n=1;
	for (int i=1;i<=m;i++){
		scanf("%d",&q[i].pd);
		if (q[i].pd==1){
			n++; int k1; scanf("%d",&k1); add(k1,n); scanf("%d",&w[n]); q[i].where=n; father[n]=k1;
		} else scanf("%d",&q[i].where);
	}
	buildtree(1,1,n);
	dfs1(1); chen(1,1,n,1,n,1); change(1,1,n,1,w[1]);
//	for (int i=1;i<=n;i++) cout<<w[i]<<" "; cout<<endl;
//	for (int i=1;i<=n;i++) cout<<dfs[i]<<" "<<r[i]<<endl;
	for (int i=1;i<=m;i++){
		if (q[i].pd==1) insert(q[i].where);
		else printf("%d\n",solve(q[i].where));
	//	cout<<"fin "<<i<<endl;
	//	for (int i=1;i<=n;i++) cout<<find(1,1,n,dfs[i],dfs[i])<<" "; cout<<endl;
	}
	return 0;
}