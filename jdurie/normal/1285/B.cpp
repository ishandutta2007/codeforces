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
#define F(i, l, r) for(ll i = l; i - r; i < r ? i++ : i--)
#define P(a) { cout << #a << " "; for(auto _ : a) cout << _ " "; cout << endl; }
#define PN(a, n) { cout << #a << " "; F(_, 0, n) cout << a[_] << " "; cout << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 100010

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T; 
    while(T--) {
        ll n; cin >> n;
        for(ll i = 0; i < n; i++)
            cin >> a[i];
        ll cur = 0, len = 0, mx = 0, I = -1;
        for(ll i = 0; i < n; i++) {
            cur += a[i];
            len++;
            if(cur > mx) {
                mx = cur;
                I = i;
            }
            if(cur <= 0) {
                len = cur = 0;
            }
        }
        cout << (I == n - 1 && a[0] > 0 && a[n - 1] > 0 && len == n && cur == mx ? "YES" : "NO") << endl;
    }
}