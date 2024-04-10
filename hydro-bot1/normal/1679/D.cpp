// Hydro submission #62dd15dd89531d052a20a622@1658656222029
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5; 
int n, m, k, a[N], b[N], f[N], deg[N];
int tot, h[N], to[N], nxt[N];
struct edge { int u, v; } e[N];
bool v[N];
int read() {
	int a=0, f=1; char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar(); 
	}
	while(isdigit(c)) a=a*10+c-'0', c=getchar();
	return a*f;
}
void add(int x,int y) { to[++tot]=y, nxt[tot]=h[x], h[x]=tot; }
bool check(int x) {
	tot=0;
	for(int i=1;i<=n;++i) h[i]=v[i]=deg[i]=0, f[i]=1;
	for(int i=1;i<=m;++i) {
		int u=e[i].u, v=e[i].v;
		if(a[u]<=x&&a[v]<=x) {
			add(u,v), ++deg[v];
		}
	}
	int cnt=0, ans=0;
	queue<int> q;
	for(int i=1;i<=n;++i) if(!deg[i]) q.push(i);
	while(q.size()) {
		int x=q.front(); q.pop();
		ans=max(ans,f[x]);
		++cnt;
		for(int i=h[x];i;i=nxt[i]) {
			int y=to[i];
			f[y]=max(f[y],f[x]+1);
			if(--deg[y]==0) q.push(y);
		}
	}
	if(cnt!=n) return 1;
	if(ans>=k) return 1;
	return 0;
}
signed main() {
	n=read(), m=read(), k=read();
	for(int i=1;i<=n;++i) b[i]=a[i]=read();
	for(int i=1;i<=m;++i) {
		e[i].u=read(), e[i].v=read();
	}
	sort(b+1,b+n+1);
	int l=1, r=n;
	while(l<r) {
		int mid=(l+r)/2;
		if(check(b[mid])) r=mid; else l=mid+1;
	}
	printf("%lld\n",check(b[l])? b[l]:-1);
}