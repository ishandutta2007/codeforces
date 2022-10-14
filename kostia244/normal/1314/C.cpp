#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1010;
struct sparse_table {
	int n;
	vector<array<int, 20>> s;
	sparse_table(vector<int> a = {}) : n(a.size()) {
		s.resize(n);
		for(int i = 0; i < n; i++) s[i][0] = a[i];
		for(int k = 1; k < 20; k++) {
			int b = 1<<(k-1);
			for(int i = 0; i < n; i++) {
				if(i+b<n) s[i][k] = min(s[i][k-1], s[i+b][k-1]);
				else s[i][k] = s[i][k-1];
			}
		}
	}
	int get(int l, int r) {
		if(l>r) return 1<<30;
		int L = r-l+1;
		L = __lg(L);
		return min(s[l][L], s[r-(1<<L)+1][L]);
	}
};
 
struct suffix_array {
	int n;
	string s;
	vector<int> sa, ra, tra, tsa, c, lcp, phi;
	sparse_table st;
	int add(int a, int b) {
		return (a+b)%n;
	}
	void radix(int k) {
		int A = max(n+2, 256);
		c.assign(A, 0);
		for(int i = 0; i < n; i++) c[ra[i]+1]++;
		for(int t, i = 1; i < A; i++) c[i] += c[i-1];
		for(int i = 0; i < n; i++) {
			tsa[c[ra[add(sa[i],k)]]++] = sa[i];
		}
		sa = tsa;
	}
	suffix_array(string _s) {
		s = _s + '\0';
		n = s.size();
		sa.resize(n);
		ra.resize(n);
		tsa.resize(n);
		tra.resize(n);
		for(int i = 0; i < n; i++) ra[i] = s[i], sa[i] = i;
		for(int k = 1; k < n; k <<= 1) {
			radix(k), radix(0);
			int r = 0;
			ra[sa[0]] = 0;
			for(int i = 1; i < n; i++) {
				r += ra[sa[i]] != ra[sa[i-1]] || ra[add(sa[i], k)] != ra[add(sa[i-1], k)];
				tra[sa[i]] = r;
			}
			ra = tra;
		}
		compute_lcp();
		st = sparse_table(lcp);
	}
	
	void compute_lcp() {
		lcp.resize(n);
		phi.resize(n);
		for(int i = 0; i < n; i++) phi[sa[i]] = i;
		for(int L = 0, i = 0; i < n; i++) {
			if(!phi[i]) lcp[phi[i]] = L = 0;
			else {
				int prev = sa[phi[i]-1];
				while(s[i+L] == s[prev+L]) L++;
				lcp[phi[i]] = L;
			}
			if(L) L--;
		}
	}
	
	int cmp(string &t, int p) {
		for(int i = 0; i < t.size(); i++)
			if(t[i] != s[p+i]) return t[i] > s[p+i] ? 0 : 2;
		return 1;
	}
	int count_substr(string t) {
		int l = -1, r = -1;
		for(int z = 1<<20; z>>=1;)
			if(l+z < n && cmp(t, sa[l+z]) < 1) l += z;
		for(int z = 1<<20; z>>=1;)
			if(r+z < n && cmp(t, sa[r+z]) <= 1) r += z;
		return r-l;
	}
	ll unique_substrings() {		
		ll ans = n * 1ll * (n - 1) / 2;
		for(int i = 0; i < n; i++) {
			ans -= lcp[i];
		}
		return ans;
	}
	int find_lcp(int i, int j) {
		return st.get(min(phi[i], phi[j])+1, max(phi[i], phi[j]));
	}
	bool less(pair<int, int> s1, pair<int, int> s2) {
		int l = find_lcp(s1.first, s2.first);
		if(s1.first+l > s1.second || s2.first+l > s2.second)
			return s1.second-s1.first < s2.second-s2.first;
		return s[s1.first+l] < s[s2.first+l];
	}
};
ll n, m, k;
string s;
const ll inf = 2e18;
void add(ll &a, ll b) {
	a = min(a+b, inf);
}
ll dp[maxn][maxn];
int link[maxn];
bool count() {
	memset(dp, 0, sizeof dp);
	if(link[0] <= n) dp[link[0]][1] = 1;
	for(int i = 0; i <= n; i++) {
		//cout << i << " -> " << link[i] << '\n';
		for(int j = 0; j <= m; j++) {
			if(i) add(dp[i][j], dp[i-1][j]);
		//	cout << i << " " << j << " " << dp[i][j] << endl;
			if(i != n && link[i] <= n) add(dp[link[i]][j+1], dp[i][j]);
		}
	}
	//cout << dp[n][m] << '\n';
	return dp[n][m] < k;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k >> s;
	suffix_array sa(s);
	vector<array<int, 2>> sub;
	sub.reserve(n*(n+1)/2);
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			sub.push_back({i, j});
	sort(all(sub), [&](auto &i, auto &j) {
		return sa.less(pair<int, int>{i[0], i[1]}, pair<int, int>{j[0], j[1]});
	});
	reverse(all(sub));
	for(auto [l, r] : sub) {
	//	for(; l <= r; l++) cout << s[l]; cout << endl;
	}
	//cout << "===\n";
	int c = -1;
	for(int z = 1<<20; z>>=1;) {
		if(c+z > sub.size()) continue;
		memset(link, 0x3f, sizeof link);
		for(int i = 0; i < c+z; i++) {
			link[sub[i][0]] = min(link[sub[i][0]], sub[i][1]+1);
		}
		//cout << c+z << ":\n";
		if(count()) c+=z;
	}
	for(int i = sub[c][0]; i <= sub[c][1]; i++) cout << s[i]; cout << endl;
}