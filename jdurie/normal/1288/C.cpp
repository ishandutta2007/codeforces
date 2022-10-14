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
#define N 1010

ll dp[30][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    G(n) G(m)
    F(j, 1, n + 1) dp[0][j] = 1;
    F(i, 1, 2 * m)
        F(j, 1, n + 1)
            F(k, 1, j + 1) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
    ll sm = 0;
    F(j, 1, n + 1) sm = (sm + dp[2 * m - 1][j]) % M;
    cout << sm << endl;
}