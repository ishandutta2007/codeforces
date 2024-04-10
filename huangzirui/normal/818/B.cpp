#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
const int maxn=2e5+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
int T,n,m,vis[maxn],a[maxn],b[maxn];
int main(){
	T=1;
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=m;i++)
			b[i]=read();
		for(int i=1;i<=n;i++)
			a[i]=vis[i]=0;
		int flag=1;
		for(int i=1;i<m;i++){
			int t=(b[i+1]-b[i]+n-1)%n+1;
			if(a[b[i]]==t)continue;
			if(vis[t]||(a[b[i]]&&a[b[i]]!=t)){flag=0;break;}
			a[b[i]]=t;vis[t]=1;
		}
		if(!flag){puts("-1");continue;}
		for(int i=1,las=1;i<=n;i++)
			if(!a[i]){
				while(vis[las])++las;
				a[i]=las++;
			}
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);puts("");
	}
    return 0;
}