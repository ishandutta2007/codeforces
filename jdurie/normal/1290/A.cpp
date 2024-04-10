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
#define N 4000

ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(n) G(m) G(k)
        k = min(m - 1, k);
        F(i, 0, n) cin >> a[i];
        ll ans = 0;
        F(l, 0, k + 1) {//l things filled
            ll temp = LLONG_MAX;
            for(ll d = 0; d <= m - 1 - k; d++)//from 0 to m - 1 - k things filled
                temp = min(temp, max(a[l + d], a[n - 1 - (m - 1 - l - d)]));
            ans = max(ans, temp);
        }
        cout << ans << endl;
    }
}