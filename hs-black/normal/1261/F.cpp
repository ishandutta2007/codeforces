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

#define Pa pair<ll, ll>  
void spl(int dep, ll l, ll r, ll L, ll R, vector<Pa> &v) {
	if (L <= l && r <= R) return v.push_back(MP(dep, l));
	ll mid = (l + r) >> 1;
	if (L <= mid) spl(dep - 1, l, mid, L, R, v);
	if (mid < R) spl(dep - 1, mid + 1, r, L, R, v);
}

ll l, r, n;

vector<Pa> ans, A, B;
void merge(Pa a, Pa b) {
	ll len = (1ll << max(a.fi, b.fi));
	ll X = a.se ^ b.se; X -= X & (len - 1);
	ans.push_back(MP(X, X ^ (len - 1)));
}

const int P = 998244353, inv = (P + 1) / 2;
int main() {
	read(n);
	for (int i = 1;i <= n; i++) 
		read(l), read(r), spl(60, 0, (1ll << 60) - 1, l, r, A);
	read(n);
	for (int i = 1;i <= n; i++)
		read(l), read(r), spl(60, 0, (1ll << 60) - 1, l, r, B);
	ll las = -1;
	for (Pa a: A) { las = -1; ll al = (1ll << a.fi) - 1;
		for (Pa b: B) if (a.fi > b.fi) {
			if (las == b.se - (b.se & al)) continue;
			las = b.se - (b.se & al), merge(a, b);
//			cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << endl;
		}
	}
	for (Pa b: B) { las = -1; ll al = (1ll << b.fi) - 1;
		for (Pa a: A) if (a.fi <= b.fi) {
			if (las == a.se - (a.se & al)) continue;
			las = a.se - (a.se & al), merge(a, b);
//			cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << endl;
		}
	}
	sort(ans.begin(), ans.end());
	ll Ans = 0, r = -1; las = 0;
	for (auto v: ans) {
		if (r < v.fi) Ans = (Ans + (las + r) % P * ((r - las + 1) % P) % P * inv) % P, las = v.fi;
		Mx(r, v.se);
//		cout << v.fi << ' ' << v.se << endl;
	}
	Ans += (las + r) % P * ((r - las + 1) % P) % P * inv;
	write(Ans % P);
	return 0;
}