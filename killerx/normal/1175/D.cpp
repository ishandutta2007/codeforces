#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define eps 1e-10
#define inf 0x3f3f3f3f
#define mod 1000000007
#define linf 1LL << 60

#define ll long long
#define ld long double
#define vi vector <int>
#define vpii vector <pii>
#define pii pair <int, int>

#define os ostream
template <typename T1, typename T2>
os & operator << (os & out, pair <T1, T2> x) {
	return out << "(" << x.first << "," << x.second << ")";
}
#define dbg(x) cerr << #x << " = " << x << endl
#define rep(i,n) for (int i = 0, Ed = (int) (n); i < Ed; ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)
#define fio(fn) freopen(fn".in", "r", stdin), freopen(fn".out", "w", stdout)
#define fastio() ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)

template <typename T = int>
inline T read() {
	T x = 0; int f = 1, c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == 45) f ^= 1;
	for (;  isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

template <typename T>
inline void write(T x) {
	int stk[20], tp = 0;
	if (x < 0) putchar(45), x = -x;
	if (!x) putchar(48);
	for (; x; stk[tp ++] = x % 10, x /= 10);
	for (; tp; putchar(48 + stk[-- tp]));
}

#define N 1 << 20

int main() {
	int n = read(), k = read();
	vi a(n);
	rep(i, n) a[i] = read();
	vector <ll> sum(n + 1);
	for (int i = n - 1; ~i; -- i) sum[i] = sum[i + 1] + a[i];
	vector <ll> v;
	rep(i, n) if (i) v.pb(sum[i]);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ll ans = 0;
	rep(i, k - 1) ans += v[i];
	ans += sum[0];
	write(ans); putchar(10);
	return 0;
}