#include <bits/stdc++.h>
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

using ull = long long;
const ull N = 600100;
const ull BASE1 = 7;
const ull BASE2 = 5;
const ull MOD1 = 1e9+7;
const ull MOD2 = 666013;

ull n, m, pBase1[N], pBase2[N];
set <pair<ull, ull>> v[N];
string s;

pair<ull, ull> H(string s) {
	ull ret1 = 0;
	ull ret2 = 0;
	for(ull i = 0; i < s.size(); i++) {
		ret1 = (ret1 + pBase1[i] * (s[i] - 'a' + 1)) % MOD1; 
		ret2 = (ret2 + pBase2[i] * (s[i] - 'a' + 1)) % MOD2;
	}
	return {ret1, ret2};
}

void pre() {
	pBase1[0] = 1;
	for(ull i = 1; i < N; i++)
		pBase1[i] = (pBase1[i - 1] * BASE1) % MOD1;
	pBase2[0] = 1;
	for(ull i = 1; i < N; i++)
		pBase2[i] = (pBase2[i - 1] * BASE2) % MOD2;
}

string check(string s) {
	auto hsh = H(s);

	for(ull i = 0; i < s.size(); i++) {
		ull h21 = (hsh.st + MOD1 - ((pBase1[i] * (s[i] - 'a' + 1)) % MOD1)) % MOD1;
		ull h22 = (hsh.nd + MOD2 - ((pBase2[i] * (s[i] - 'a' + 1)) % MOD2)) % MOD2;

		for(ull add = 1; add <= 3; add++) {
			if(add == s[i] - 'a' + 1) continue;
			ull hhh1 = (h21 + pBase1[i] * add) % MOD1;
			ull hhh2 = (h22 + pBase2[i] * add) % MOD2;

			if(v[s.size()].count({hhh1, hhh2}))
				return "YES";
		}
	}
	return "NO";
}

int main() {
	ios_base::sync_with_stdio(false);	
	pre();
	cin >> n >> m;
	for(ull i = 1; i <= n; i++) {
		cin >> s;
		v[s.size()].insert(H(s));
	}

	// dbg(v[26]);

	for(ull i = 1; i <= m; i++) {
		cin >> s;
		cout << check(s) << '\n';
	}
}