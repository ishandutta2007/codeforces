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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 400050;
vector<int> v[N];
int mx[N], mmx[N], vis[N], n, a;

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x;
		x = x * x; mi >>= 1;
	}
	return res;
}

const int Maxn = 200000;
int main() {
	memset(mx, 0x3f, sizeof(mx));
	memset(mmx, 0x3f, sizeof(mmx));
	for (int i = 2;i <= Maxn; i++) {
		if (v[i].size()) continue;
		for (int j = i;j <= Maxn; j += i)
			v[j].push_back(i);
	}
	read(n);
	for (int i = 1;i <= n; i++) {
		read(a); int x = a;
		for (int j = 0;j < v[a].size(); j++) {
			int p = v[a][j], c = 0; vis[p]++;
			while (x % p == 0) x /= p, c++;
			if (mx[p] > c) mmx[p] = mx[p], mx[p] = c;
			else if (mmx[p] > c) mmx[p] = c;
		}
	}
	ll ans = 1;
	for (int i = 2;i <= Maxn; i++) {
		if (vis[i] <= n - 2) continue;
		if (vis[i] == n - 1) ans *= fpw(i, mx[i]);
		else ans *= fpw(i, mmx[i]);
	}
	write(ans);
	return 0;
}