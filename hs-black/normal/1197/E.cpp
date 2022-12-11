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

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 500050;
const int P = 1e9+7;
ll fx[N], sg[N], f[N], g[N], n; 
struct node {
	ll a, b;
	bool operator < (const node &i) const {
		return b < i.b;
	}
}p[N];

int main() {
	read(n); ll mx = 0;
	for (int i = 1;i <= n; i++) read(p[i].b), read(p[i].a), Mx(mx, p[i].a);
	sort(p + 1, p + n + 1);
	sg[0] = g[0] = 1;
	for (int i = 1;i <= n; i++) {
		int x = upper_bound(p + 1, p + n + 1, (node){0, p[i].a}) - p - 1;
		Mn(x, i-1);
		f[i] = fx[x] + p[i].a, g[i] = sg[x]; ll t = f[i] - p[i].b;
		if (t < fx[i-1] || i == 1) fx[i] = t, sg[i] = g[i];
		else if (t == fx[i-1] && i != 1) fx[i] = t, sg[i] = (g[i] + sg[i-1]) % P;
		else fx[i] = fx[i-1], sg[i] = sg[i-1];
	}
	
	ll a1 = 1e15, a2 = 0;
	for (int i = n;i >= 1; i--) {
		if (p[i].b <= mx) break;
		if (f[i] < a1) a1 = f[i], a2 = g[i];
		else if (f[i] == a1) a2 += g[i];
	}
	
	printf ("%lld\n", a2 % P);
	
	return 0;
}