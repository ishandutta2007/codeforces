#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,mod,k;
int f[maxn];
int num[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
inline int power(int x,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=k=read();m=read();mod=read();
	for(int i=1;i<=n;i++)f[i]=i,num[i]=1;
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();v=read();
		u=find(u);v=find(v);
		if(u==v)continue;
		f[u]=v;
		num[v]+=num[u];
		k--;
	}
	int p=1;
	for(int i=1;i<=n;i++)if(i==f[i])p=1ll*p*num[i]%mod;
    if(k>=2)printf("%d\n",1ll*power(n,k-2)*p%mod);
	else printf("%d\n",1%mod);
	return 0;
}