//String Hashing
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef pair<unsigned ll, ll> hsh;

#define K first
#define V second
#define M 1000000321
#define OP(x, y) constexpr hsh operator x (const hsh a, const hsh b) { return { a.K x b.K, (a.V y b.V) % M }; }
OP(+, +) OP(*, *) OP(-, + M -)
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> dist(256, M - 1);

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define EQ(i, j, l) ((h[i + l] - h[i]) * p[j] == (h[j + l] - h[j]) * p[i]) //does s[i, i + l) == s[j, j + l)
#define PERIODIC(l, r, k) (l + k > r || EQ(l, l + k, r - l - k)) //is s[l, r) periodic with period k
#define REV_IDX(i) (2 * n - (i))
#define PALIND(i, j) EQ(i, REV_IDX(j), j - i + 1)
#define N 2000010

string s;
hsh p[N], h[N], base = { dist(gen) | 1, dist(gen) };
ll n;

ll lcp(ll i, ll j, ll l, ll r) { //for l = 0, returns length of lcp of s[i, i + r) and s[j, j + r)
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return EQ(i, j, m) ? lcp(i, j, m, r) : lcp(i, j, l, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> s; n = s.size();
        s = s + '$'; FD(i, n - 1, -1) s += s[i];
        p[0] = { 1, 1 };
        F(i, 1, s.size() + 1) h[i] = h[i - 1] + (p[i] = p[i - 1] * base) * make_pair(s[i - 1], s[i - 1]);
        if(PALIND(0, n - 1)) cout << s.substr(0, n) << '\n';
        else {
            ll m = lcp(0, n + 1, 0, n);
            ll lenL = 0, lenR = 0;
            F(j, m, n - m) if(PALIND(m, j)) lenL = j - m + 1;
            FD(j, n - m - 1, m - 1) if(PALIND(j, n - m - 1)) lenR = n - m - j;
            cout << s.substr(0, m);
            if(lenL > lenR) cout << s.substr(m, lenL);
            else cout << s.substr(n - m - lenR, lenR);
            cout << s.substr(n - m, m) << '\n';
        }
    }
}