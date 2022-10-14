//String Hashing
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> hsh;

#define K first
#define V second
#define M 1000000321
#define OP(x, y) constexpr hsh operator x (const hsh a, const hsh b) { return { a.K x b.K, (a.V y b.V) % M }; }
OP(+, +) OP(*, *) OP(-, + M -)
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> dist(256, M - 1);

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define H(i, l, j) ((h[(i) + (l)] - h[i]) * p[j])
#define EQ(i, j, l) (H(i, l, j) == H(j, l, i)) //s[i, i + l) == s[j, j + l)
#define N 1000010

string s;
hsh p[N], h[N], base = { dist(gen) | 1, dist(gen) };
ll n;
vector<ll> lens;

bool works(ll m) {
    F(i, 1, n - lens[m]) if(EQ(0, i, lens[m])) return true;
    return false;
}

ll bSearch(ll l, ll r) {
    if(l == r) return lens[l];
    ll m = (l + r + 1) / 2;
    return works(m) ? bSearch(m, r) : bSearch(l, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s; n = s.size();
    p[0] = { 1, 1 };
    F(i, 1, s.size() + 1) h[i] = h[i - 1] + (p[i] = p[i - 1] * base) * make_pair(s[i - 1], s[i - 1]);
    F(i, 1, n) if(EQ(0, n - i, i)) lens.push_back(i);
    sort(lens.begin(), lens.end());
    if(lens.empty() || !works(0)) cout << "Just a legend\n";
    else cout << s.substr(0, bSearch(0, lens.size() - 1)) << '\n';
}