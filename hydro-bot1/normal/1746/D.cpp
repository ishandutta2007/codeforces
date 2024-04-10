// Hydro submission #635a7847761b032d5629b84f@1666873416523
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define SET(a,b) memset(a,b,sizeof(a))
int read() {
	int a=0, f=1; char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) a=a*10+c-'0', c=getchar();
	return a*f;
}
const int N=2e5+5;
int t, n, k, ans, s[N], f[N];
int tot, h[N], to[2*N], nxt[2*N];
void add(int x,int y) {
	to[++tot]=y, nxt[tot]=h[x], h[x]=tot;
}
void addedge(int x,int y) {
	add(x,y), add(y,x);
}
void dp(int x,int fa,int kk) {
	ans+=kk*s[x];
	int cnt=0;
	for(int i=h[x];i;i=nxt[i]) if(to[i]!=fa) ++cnt;
	if(!cnt) { f[x]=s[x]; return; }
	priority_queue<int> q;
	int d=kk/cnt, p=kk%cnt;
	for(int i=h[x];i;i=nxt[i]) {
		int y=to[i];
		if(y==fa) continue;
		dp(y,x,d);
		q.push(f[y]);
	}
	while(p--) ans+=q.top(), q.pop();
	f[x]=q.top()+s[x];
}
void solve() {
	n=read(), k=read();
	tot=ans=0;
	for(int i=1;i<=n;++i) h[i]=f[i]=0;
	for(int i=2;i<=n;++i) {
		int p=read();
		addedge(i,p);
	}
	for(int i=1;i<=n;++i) s[i]=read();
	dp(1,1,k);
	printf("%lld\n",ans);
}
signed main() {
	t=read();
	while(t--) solve();
}