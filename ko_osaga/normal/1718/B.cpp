#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int mod = 1e9 + 7;

struct mint {
    int val;
    mint() { val = 0; }
    mint(const lint& v) {
        val = (-mod <= v && v < mod) ? v : v % mod;
        if (val < 0) val += mod;
    }

    friend ostream& operator<<(ostream& os, const mint& a) { return os << a.val; }
    friend bool operator==(const mint& a, const mint& b) { return a.val == b.val; }
    friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { return a.val < b.val; }

    mint operator-() const { return mint(-val); }
    mint& operator+=(const mint& m) { if ((val += m.val) >= mod) val -= mod; return *this; }
    mint& operator-=(const mint& m) { if ((val -= m.val) < 0) val += mod; return *this; }
    mint& operator*=(const mint& m) { val = (lint)val*m.val%mod; return *this; }
    friend mint ipow(mint a, lint p) {
        mint ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mint inv(const mint& a) { assert(a.val); return ipow(a, mod - 2); }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }

    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
    operator int64_t() const {return val; }
};

lint dp[50];

int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	dp[0] = dp[1] = 1;
	for(int i = 2; i < 50; i++) dp[i] = dp[i-1] + dp[i-2];
	while(t--){
		int n; cin >> n;
		auto zeck = [&](lint x){
			vector<int> ans;
			for(int i = 49; i >= 0; i--){
				while(x >= dp[i]){
					x -= dp[i];
					ans.push_back(i);
				}
			}
			return ans;
		};
		vector<int> a(n);
		vector<vector<int>> z(n);
		int cnt[51] = {};
		for(int i = 0; i < n; i++){
			cin >> a[i];
			z[i] = zeck(a[i]);
			for(int j = 0; j < sz(z[i]); j++){
				cnt[z[i][j]]++;
			}
		}
		bool dap = 0;
		for(int i = 0; i < n; i++){
			for(auto &j : z[i]) cnt[j]--;
			auto k = zeck(a[i] - 1);
			bool ok = 1;
			for(auto &j : k){
				if(j == 1) ok = 0;
				cnt[j]++;
			}
			for(int i = 1; i < 50; i++){
				if(cnt[i] > 1) ok = 0;
				if(cnt[i] == 0 && cnt[i + 1]) ok = 0;
			}
			if(ok) dap = 1;
			for(auto &j : z[i]) cnt[j]++;
			for(auto &j : k) cnt[j]--;
		}
		if(dap) cout << "YES\n";
		else cout << "NO\n";
	}
}