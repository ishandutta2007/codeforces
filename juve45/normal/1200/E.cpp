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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 1001001;
const long long MOD = 1e9 + 9;
const long long B = 131;

long long n, pwb[N], hashes[N];
string s, ans;

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

bool ok(long long hsh, long long lg) {
	// last is ans.size()
	long long tmp = (hashes[ans.size() - lg] * pwb[lg]) % MOD;
	tmp = hashes[ans.size()] - tmp;
	tmp = (tmp + MOD) % MOD;
	// dbg(hsh, tmp);
	return (tmp == hsh);
}

int main() {
	ios_base::sync_with_stdio(false);

	pwb[0] = 1;
	for(long long i = 1; i < N; i++)
		pwb[i] = (B * pwb[i - 1]) % MOD;

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> s;

		long long hsh = 0, pre = 0;
		for(long long j = 0; j < s.size(); j++) {
			hsh = (hsh * B) % MOD + (s[j] - '0');
			hsh %= MOD;
			if(j + 1 <= ans.size() && ok(hsh, j + 1)) 
				pre = j + 1;
		}
		// dbg(pre);

		for(long long j = pre; j < s.size(); j++) {
			ans += s[j];
			hashes[ans.size()] = (hashes[ans.size() - 1] * B) % MOD + (s[j] - '0');
		}
	}
	cout << ans << '\n';
}