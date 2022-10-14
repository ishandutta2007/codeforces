#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef complex<ld> pt;     

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i != r; i < r ? i++ : i--)
#define P(a) { cout << #a << ": { "; for(auto _ : a) cout << _ << " "; cout << "}" << endl; }
#define PN(a, n) { cout << #a << ": { "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 100010
    
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	G(a) G(b)
	if(b > a) EX(-1)
	if(b == a) EX(b)
	ll k1 = (a - b) / b; k1 -= k1 % 2;
	ll k2 = a / b; k2 += k2 % 2;
	ld ans = LLONG_MAX;
	if(k1) ans = min(ans, (a - b) / (ld) k1);
	if(k2) ans = min(ans, (a + b) / (ld) k2);
	cout << fixed << setprecision(10) << ans << endl;
}