// Hydro submission #62dd448589531d052a20d18b@1658668165648
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005;
int n, m, fa[N], deg[N], f[N], op[N][N];
int tot, h[N], to[N*N], nxt[N*N];
int read() {
	int a=0, f=1; char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) a=a*10+c-'0', c=getchar();
	return a*f;
}
int get(int x) { return x==fa[x]? x:fa[x]=get(fa[x]); }
void merge(int x,int y) {
	x=get(x), y=get(y);
	if(x!=y) fa[x]=y;
}
void add(int x,int y) { to[++tot]=y, nxt[tot]=h[x], h[x]=tot; }
void toposort() {
	int cnt=0;
	vector<int> p;
	queue<int> q;
	for(int i=1;i<=n+m;++i) if(!deg[i]) f[i]=1, q.push(i);
	while(q.size()) {
		int x=q.front(); q.pop();
		++cnt;
		for(int i=h[x];i;i=nxt[i]) {
			int y=to[i];
			f[y]=max(f[y],f[x]+1);
			if(--deg[y]==0) q.push(y);
		}
	}
	if(cnt!=n+m) { puts("No"); return; }
	puts("Yes");
	for(int i=1;i<=n;++i) printf("%lld%c",f[get(i)]," \n"[i==n]);
	for(int i=1;i<=m;++i) printf("%lld%c",f[get(i+n)]," \n"[i==m]);
}
signed main() {
	n=read(), m=read();
	for(int i=1;i<=n+m;++i) fa[i]=i;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) {
		char c; scanf(" %c",&c);
		if(c=='=') merge(i,j+n);
		else op[i][j]=c=='<'? 1:2;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) {
		int x=get(i), y=get(j+n);
		if(op[i][j]&&x==y) { puts("No"); return 0; }
		if(op[i][j]==1) add(x,y), ++deg[y];
		else if(op[i][j]==2) add(y,x), ++deg[x];
	}
	toposort();
}