#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef complex<ld> pt;

template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}

#define Q(x) { cout << x << endl; return 0; }
#define S << " " <<
#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i - r; i < r ? i++ : i--)
#define R(a, n) F(_, 0, n) cin >> a[_];
#define P(a) { cout << #a << ": "; for(auto _ : a) cout << _ << " "; cout << endl; }
#define PN(a, n) { cout << #a << ": "; F(_, 0, n) cout << a[_] << "\n "[_ - n + 1]; }
#define FS first
#define SC second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 110

ll a[N], dp[N][N];
vector<ll> v[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    G(n)
    if(n == 1) Q(0)
    ll pp[2] = {n / 2, (n + 1) / 2};
    ll ans = 0;
    F(i, 0, n) { 
        cin >> a[i];
        if(a[i]) pp[a[i] % 2]--;
        if(i && a[i] && a[i - 1] && ((a[i] % 2) != (a[i - 1] % 2))) ans++;
    }
    if(pp[0] == n / 2 && pp[1] == (n + 1) / 2) Q(1)
    ll rLen = 0, par = -1;
    F(i, 0, n) {
        if(a[i]) {
            if(rLen && par != -1) {
                if(par == (a[i] % 2))
                    v[par].push_back(rLen);
                else ans++;
            }
            par = a[i] % 2;
            rLen = 0;
        } else rLen++;
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    F(i, 0, 2)
        for(ll j : v[i])
            if(pp[i] >= j) pp[i] -= j;
            else ans += 2;
    ll iS = 0;
    while(!a[iS]) iS++;
    if(pp[a[iS] % 2] >= iS)
        pp[a[iS] % 2] -= iS;
    else ans++;
    ll iE = n - 1;
    while(!a[iE]) iE--;
    if(pp[a[iE] % 2] < (n - 1 - iE))
        ans++;
    cout << ans << endl;
}