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
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 100010

set<pl> bad, lava;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(q)
    string ans = "Yes";
    F(i, 0, q) {
        G(r) G(c)
        if(lava.count({r, c})) {
            lava.erase({r, c});
            if(bad.count({r, c})) {
                bad.erase({r, c});
                for(ll dx = -1; dx <= 1; dx += 2)
                    F(dy, -1, 2)
                        if(bad.count({r + dx, c + dy})) {
                            bool stay = false;
                            for(ll DX = -1; DX <= 1; DX += 2)
                                F(DY, -1, 2)
                                    if(bad.count({r + dx + DX, c + dy + DY}))
                                        stay = true;
                            if(!stay) bad.erase({r + dx, c + dy});
                        }
                ans = bad.size() ? "No" : "Yes";
            }
        } else {
            lava.insert({r, c});
            for(ll dx = -1; dx <= 1; dx += 2)
                F(dy, -1, 2)
                    if(lava.count({r + dx, c + dy})) {
                        ans = "No";
                        bad.insert({r, c});
                        bad.insert({r + dx, c + dy});
                    }
        }
        cout << ans << endl;
    }
}