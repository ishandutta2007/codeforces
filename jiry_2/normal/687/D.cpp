#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct atom{
	int u,v,w,where;
}A[1000000];
int n,q,m,f[2000],w[2000],pd[2000];
int compare(atom k1,atom k2){
	return k1.w<k2.w;
}
int findfather(int k1){
	if (f[k1]==k1) return k1;
	int pre=f[k1]; f[k1]=findfather(f[k1]);
	w[k1]^=w[pre];
	return f[k1];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		A[i]=(atom){k1,k2,k3,i};
	}
	sort(A+1,A+m+1,compare);
	for (;q;q--){
		int l,r; scanf("%d%d",&l,&r);
		for (int i=1;i<=n;i++) f[i]=i,w[i]=0;
		int ans=-1;
		for (int i=m;i;i--){
			if (A[i].where>=l&&A[i].where<=r){
				int k1=findfather(A[i].u),k2=findfather(A[i].v);
			//	cout<<A[i].u<<" "<<A[i].v<<" "<<k1<<" "<<k2<<" "<<w[A[i].u]<<" "<<w[A[i].v]<<endl;
				if (k1!=k2){
					f[k1]=k2; w[k1]=w[A[i].u]^w[A[i].v]^1;
				} else if (w[A[i].u]==w[A[i].v]){
					ans=A[i].w; break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}