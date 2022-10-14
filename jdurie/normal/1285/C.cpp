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
#define N 100010

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    G(x)
    vector<ll> pws;
    for(ll i = 2; i * i <= x; i++) {
        ll d = 1;
        while(x % i == 0) {
            d *= i;
            x /= i;
        }
        if(d > 1)
            pws.push_back(d);
    }
    if(x > 1) pws.push_back(x);
    ll a = LLONG_MAX, b = LLONG_MAX, LEN = (1L << pws.size()), sz = pws.size();
    for(ll mask = 0; mask < LEN; mask++) {
        ll tA = 1, tB = 1;
        for(ll i = 0; i < sz; i++)
            if(mask & (1L << i))
                tA *= pws[i];
            else tB *= pws[i];
        if(max(tA, tB) < max(a, b)) {
            a = tA;
            b = tB;
        }
    }
    cout << a << " " << b << endl;
}