#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=5010;
int n,m,k;
int f[maxn][maxn],a[maxn],b[maxn],c[maxn],tr[maxn];
int head[maxn],nxt[maxn],rdc[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();m=read();k=read();
	for(register int i=1;i<=n;++i){
		a[i]=read();b[i]=read();c[i]=read();
		tr[i]=i;
	}
	for(register int i=1,u,v;i<=m;++i){
		u=read();v=read();
		tr[v]=max(tr[v],u);
	}
	for(register int i=1;i<=n;++i){
		nxt[i]=head[tr[i]];
		head[tr[i]]=i;
	}
	f[0][k]=1;
	for(register int i=1;i<=n;++i){
		if(k<a[i]){
			puts("-1");return 0;
		}
		for(register int j=a[i];j<=k;++j)
			f[i][j+b[i]]=f[i-1][j];
		k+=b[i];
		for(register int r=head[i];r;r=nxt[r])
			for(register int j=1;j<=k;++j)
				if(f[i][j])f[i][j-1]=max(f[i][j-1],f[i][j]+c[r]);
	}
	int ans=0;
	for(register int i=0;i<=k;++i)
		ans=max(ans,f[n][i]-1);
	printf("%d",ans);
    return 0;
}