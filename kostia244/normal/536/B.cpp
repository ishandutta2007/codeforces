#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 2e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define find asdfjsadjf
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int n, m;
string t, x;
vi z;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> t;
	x = t + "#" + t;
	z = z_function(x);
	string s(n, '.');
	vi g;
	g.resize(m);
	for(auto &i : g) cin >> i;
	reverse(all(g));
	for(auto p : g) {
		--p;
		for(int i = 0; i < t.size(); i++) {
			if(s[p+i] == '.') s[p+i] = t[i];
			else {
				if(i&&i+z[t.size() + 1 + i]!=t.size()) return cout << 0, 0;
				break;
			}
		}
	}
	ll ans = 1;
	for(auto i : s) if(i == '.') ans = (ans*26ll)%mod;
	cout << ans;
}