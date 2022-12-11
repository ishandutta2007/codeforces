#include<bits/stdc++.h>
#define ll double
using namespace std;
template<typename T> inline void read(T &x)
{
	x=0;char c=getchar();bool flag=false;
	while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	if(flag)x=-x;
}

int n, m;
const int N = 200500;
int h[N], ne[N<<1], to[N<<1];
int w[N<<1], siz[N], tot;
inline void add(int x,int y,int z) {
	ne[++tot] = h[x], h[x] = tot;
	to[tot] = y, w[tot] = z;
}

int x[N], y[N], f[N], val[N];

void dfs(int x,int fa) {
	f[x] = fa, siz[x] = 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs(y, x); siz[x] += siz[y];
	}
}

ll work(int x,int y,int val) {
	if (f[y] == x) swap(x, y);
	ll sx = siz[x], sy = n - sx;
	ll ans = 0;
	ans = (sx * (sx-1) / 2 * sy) + (sx * sy * (sy - 1) / 2);
	return ans * val;
}

int main()
{
	read(n);
	ll tmp = (ll) n * (n-1) * (n-2) / 12;
	for (int i = 1;i < n; i++) {
		read(x[i]), read(y[i]), read(val[i]);
		add(x[i], y[i], val[i]);
		add(y[i], x[i], val[i]);
	}
	dfs(1, 0);
	ll ans = 0;
	for (int i = 1;i < n; i++) ans += work(x[i], y[i], val[i]);
	read(m);
	for (int i = 1;i <= m; i++) {
		int a, b; read(a), read(b);
		ans -= work(x[a], y[a], val[a]);
		val[a] = b;
		ans += work(x[a], y[a], val[a]);
		cout << fixed << setprecision(8) << ans / tmp << endl;
	}		
	return 0;
}