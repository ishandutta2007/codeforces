#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct ask{
	int l,r,where;
}q[210000];
const int mo=1e9+7,N=1000000;
int A[210000],x[210000],pd[1100000],n,m,B[210000],where[1100000],ans[210000];
vector<int>p[1100000];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int compare(ask k1,ask k2){
	return k1.r<k2.r;
}
void add(int k1,int k2){
	if (k1==0) return;
	for (;k1<=n;k1+=k1&(-k1)) B[k1]=1ll*B[k1]*k2%mo;
}
int find(int k1){
	int ans=1; for (;k1;k1-=k1&(-k1)) ans=1ll*ans*B[k1]%mo; return ans;
}
void addin(int k1,int k2){
	int w=1ll*(k1-1)*quick(k1,mo-2)%mo;
	add(where[k1],quick(w,mo-2));
	add(k2,w); where[k1]=k2;
}
void insert(int k1){
	int w=x[k1];
	for (int i=0;i<p[w].size();i++){
		int k2=p[w][i];
		addin(k2,k1);
	}
}
int getans(int L,int R){
	return 1ll*A[R]*quick(A[L-1],mo-2)%mo*find(R)%mo*quick(find(L-1),mo-2)%mo;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	scanf("%d",&m);;
	A[0]=1; for (int i=1;i<=n;i++) A[i]=1ll*A[i-1]*x[i]%mo;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r); q[i].where=i;
	}
	sort(q+1,q+m+1,compare);
	for (int i=1;i<=n;i++) B[i]=1;
	for (int i=2;i<=N;i++)
		if (pd[i]==0)
			for (int j=i;j<=N;j+=i) {
				pd[j]=1; p[j].push_back(i);
			}
	int now=1;
	for (int i=1;i<=n;i++){
		insert(i);
		while (now<=m&&q[now].r==i) ans[q[now].where]=getans(q[now].l,q[now].r),now++;
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}