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
#define INT(x) { cout << x << endl; }
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 2000

set<ll> qs[N];
set<ll> ps[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(k)
    F(q, 0, n / k) {
        F(i, q * k, (q + 1) * k) {
            INT("? " << (i + 1)) GS(res)
            if(res == "N") qs[q].insert(i);
        }
        INT("R")
    }
    F(q, 0, n / k) while(qs[q].size() > ps[q].size()) {
        ll x = *qs[q].begin();
        ps[q].insert(x);
        qs[q].erase(x);
    }
    F(q1, 0, n / k)
        F(q2, q1 + 1, n / k) {
            set<ll> rems;
            F(mask, 0, 4) {
                set<ll> s1 = mask & 1 ? qs[q1] : ps[q1];
                set<ll> s2 = mask & 2 ? qs[q2] : ps[q2];
                for(ll i : s1) {
                    INT("? " << (i + 1)) GS(res)
                    if(res == "Y") rems.insert(i);
                }
                for(ll i : s2) {
                    INT("? " << (i + 1)) GS(res)
                    if(res == "Y") rems.insert(i);
                }
                INT("R")
            }
            for(ll x : rems) {
                qs[q1].erase(x);
                qs[q2].erase(x);
                ps[q1].erase(x);
                ps[q2].erase(x);
            }
        }
    ll ans = 0;
    F(i, 0, n / k) ans += qs[i].size() + ps[i].size();
    INT("! " << ans)
}