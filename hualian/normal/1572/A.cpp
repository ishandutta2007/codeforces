#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
//#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
int n,deg[N],f[N];
vector<int> g[N];
queue<int> q;
int topo(){
	int tot=0,ret=0;
	For(i,1,n)if(!deg[i])q.push(i),f[i]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		tot++,ret=max(ret,f[u]);
		for(int v:g[u]){
			f[v]=max(f[v],f[u]+(u>v));
			if(!--deg[v])q.push(v);
		}
	}return tot<n?-1:ret;
}
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())deg[i]=f[i]=0,g[i].clear();
		For(i,1,n){
			deg[i]=read();For(j,1,deg[i])g[read()].push_back(i);
		}printf("%d\n",topo());
	}
	return 0;
}