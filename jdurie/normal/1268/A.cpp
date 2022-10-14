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
#define N 200010

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(k)
    GS(s)
    F(i, 0, n) a[i] = s[i] - '0';
    bool gtr = false;
    F(i, k, n)
        if(a[i] > a[i - k]) { gtr = true; break; }
        else if(a[i] < a[i - k]) break;
    if(gtr) a[k - 1]++;
    ll ind = k - 1;
    while(ind >= 0 && a[ind] == 10) {
        a[ind] = 0;
        ind--;
        a[ind]++;
    }
    cout << n << endl;
    F(i, 0, n) cout << a[i % k];
    cout << endl;
}