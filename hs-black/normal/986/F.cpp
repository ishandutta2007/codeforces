
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int Maxn = 32000000;
const int Pim = 30000000;
const int N = 200050;
int e[Maxn + 55], prime[Pim], tot;

struct node {
	ll n, k; int num;
	bool operator < (const node &i) const {
		return k < i.k;
	}
}qy[N];

void prework(void) {
	for (int i = 2;i <= Maxn; i++) {
		if (!e[i]) prime[++tot] = e[i] = i;
		for (int j = 1;j <= tot; j++) {
			int t = prime[j] * i; if (t > Maxn) break;
			e[t] = prime[j]; if (e[i] == prime[j]) break;
		}
	}
}

ll st[N], dis[N], tp; int vis[N];
priority_queue<pair<ll, int> > q;
void work(ll k) {
	tp = 0;
	for (int i = 1, t;(ll)prime[i] * prime[i] <= k; i++) {
		if (k % (t = prime[i])) continue;
		st[++tp] = t;
		while (k % t == 0) k /= t;
	}
	if (k != 1) st[++tp] = k;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	if (tp == 2) swap(st[1], st[2]);
	if (tp >= 3) {
		dis[0] = 0, q.push(MP(0, 0));
		while (q.size()) {
			int x = q.top().se; q.pop();
			if (vis[x]) continue; vis[x] = 1;
			for (int i = 2;i <= tp; i++) {
				int y = (x + st[i]) % st[1]; 
				ll t = (x + st[i]) / st[1];
				if (dis[y] > dis[x] + t) 
					dis[y] = dis[x] + t, q.push(MP(-dis[y], y));
			}
		}
	}
}

/*

ax + by = 1
bx + (a - a / b * b) y = 1
ay + b(x - a / b * y) = 1

*/

void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, void();
	exgcd(b, a % b, x, y);
	ll t = x; x = y, y = t - a / b * y;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

bool solve(ll n) {
	if (!tp) return 0;
	if (tp == 1) return n % st[1] == 0;
	if (tp == 2) {
		ll t1 = st[1], t2 = st[2], x, y;
		exgcd(t1, t2, x, y);
		x = (x % t2 + t2) % t2;
		ll tt = n % t2;
		x = x * tt % t2;
		return n >= x * t1;
	}
	return n >= dis[n % st[1]] * st[1] + (n % st[1]);
}

int ans[N], T;
int main() {
//	freopen ("hs.in","r",stdin);
//	freopen ("hs.out","w",stdout);
	read(T), prework();
	for (int i = 1;i <= T; i++) read(qy[i].n), read(qy[i].k), qy[i].num = i;
	sort(qy + 1, qy + T + 1);
	for (int l = 1, r;l <= T; l = r + 1) {
		work(qy[l].k), r = l;
		while (qy[r + 1].k == qy[l].k) r++;
		for (int i = l;i <= r; i++)
			ans[qy[i].num] = solve(qy[i].n);
	}
	for (int i = 1;i <= T; i++) puts(ans[i] ? "YES" : "NO");
	return 0;
}

/*

1 1
90355095012 990455925079

*/