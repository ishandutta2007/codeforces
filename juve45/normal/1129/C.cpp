#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(ull _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


using ull = unsigned long long;

const ull N = 3010;
const ull MOD = 1e9 + 7;
const ull BASE = 2;

int n, k, m, a, ans, nr = 1;
unordered_map <string, int> mp;
string s;

int go[2][N * N], val[N * N];

int hashes[N][N], ind[N][N], dp[N * N / 2];

void pre() {
	ull k = 1;
	mp["0011"] = -1;
	mp["0101"] = -1;
	mp["1110"] = -1;
	mp["1111"] = -1;
}


void compute(int x, int y) {

	int curr = nr;
	hashes[x][y] = nr++;
	
	for(int i = 1; i <= 4 && i <= y - x + 1; i++) {
		if(mp[s.substr(y - i + 1)] == -1) continue;
		dp[curr] += dp[hashes[x][y - i]];
		dp[curr] %= MOD;
	}
	ans += dp[curr];
	ans %= MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	pre();

	dp[0] = 1;
	memset(go, -1, sizeof go);

	char a;
	s = "#";
	for(ull i = 1; i <= n; i++) {
		cin >> a;
		s += a;

		hashes[i][i] = go[s[i] - '0'][0];
		if(hashes[i][i] == -1) {
			go[s[i] - '0'][0] = nr;
			compute(i, i);
		}


		for(int j = 1; j < i; j++) {
			hashes[j][i] = go[s[i] - '0'][hashes[j][i - 1]];

			if(hashes[j][i] == -1) {
				go[s[i] - '0'][hashes[j][i - 1]] = nr;
				compute(j, i);
			}
		}
		cout << ans << '\n';
	}
}