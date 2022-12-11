#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 2005000;
ll c[N], n, m, cnt;

vector<int> v[N];
int bl[N], to[N];

bool cmp(int a, int b) {
	return bl[a] < bl[b];
}

ll f[N], T;

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a; }

int main() {
	read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1;i <= n; i++) read(c[i]), bl[i] = 0, v[i].clear();
		for (int i = 1;i <= m; i++) {
			int x, y; read(x), read(y);
			v[x].push_back(y);
		}
		int pre = -1;
		for (int i = 1;i <= n; i++) {
			pre = -1;
			if (!v[i].size()) continue;
			sort(v[i].begin(), v[i].end(), cmp);
			for (int j = 0;j < v[i].size(); j++) {
				if (bl[v[i][j]] != pre) cnt++;
				pre = bl[v[i][j]], bl[v[i][j]] = cnt;
			}
		}
		
		ll ans = 0;
		for (int i = 1;i <= n; i++) f[bl[i]] += c[i];
		for (int i = 1;i <= cnt; i++) {
			if (!f[i]) continue;
			ans = gcd(f[i], ans);
			f[i] = 0;
		}
		printf ("%lld\n", ans);
		cnt = 0;
	}
	return 0;
}