#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=4e5+9;
int n,q;
int a[M],b[M],L[M],R[M],c[M],v[M];
void add(int i,int x){
	for(;i<=n*2;i+=i&-i)b[i]=(b[i]+x)%mod;
}
int sum(int i,int rex=0){
	for(;i;i-=i&-i)rex=(rex+b[i])%mod;
	return rex;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&L[i],&R[i]);
		c[R[i]]=i;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+q+1,[&](const int&l,const int&r){return R[l]>R[r];});
	for(int i=1;i<=n*2;++i){
		if(c[i]){
			int x=c[i];
			v[x]=(1ll*sum(R[x])-sum(L[x])+mod+1)%mod;
			add(L[x],v[x]);
		}
	}
	int ans=0;
	for(int i=1,l=0,r=n*2;i<=q;++i){
		int x=a[i];
		if(R[x]<l)break;
		while(r>=R[x]){
			if(c[r])add(L[c[r]],-v[c[r]]);
			r--;
		}
		if(L[x]<l)continue;
		ans=(1ll*ans+sum(R[x])-sum(l)+1+mod)%mod;
		l=L[x];
	}
	printf("%d\n",ans);
	return 0;
}