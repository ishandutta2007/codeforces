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
#define P(a) { cout << #a << " "; for(auto _ : a) cout << _ << " "; cout << endl; }
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
#define N 300010

ll n, mm;
ll a[N][10];
map<ll, ll> mp;

pl works(ll m) {
    mp.clear();
    F(i, 0, n) {
        ll mask = 0;
        F(j, 0, mm)
            if(a[i][j] >= m) mask |= 1 << j;
        if(mask == ((1 << mm) - 1)) return {i, i};
        for(auto x : mp)
            if((x.K | mask) == ((1 << mm) - 1))
                return {i, x.V};
        mp[mask] = i;
    }
    return {-1, -1};
}

pl bSearch(ll l, ll r) {
    if(l == r) return works(l);
    ll m = (l + r + 1) / 2;
    return works(m).K != -1 ? bSearch(m, r) : bSearch(l, m - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> mm;
    F(i, 0, n) F(j, 0, mm) cin >> a[i][j];
    pl ans = bSearch(0ll, 1000000000ll);
    cout << (ans.first + 1) << " " << (ans.second + 1) << endl;
}