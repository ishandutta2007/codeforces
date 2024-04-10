#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1010;
const int MOD = 1e9 + 7;
int n, k, dp[N], comb[N][N];
string s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

void pre() {		
	comb[0][0] = 1;
	comb[1][0] = comb[1][1] = 1;
	for(int i = 2; i <= 1000; i++) {
		comb[i][0] = 1;
		for(int j = 1; j <= i; j++)
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
	}
}	

int get(int nr) {
	int off = 0, ret = 0;
	for(int i = 0; i < s.size() && off <= nr; i++)
		if(s[i] == '1') {
			ret = (ret + comb[s.size() - i - 1][nr - off]) % MOD;
			off++;
		}
	if(off == nr)
		ret = (ret + 1) % MOD;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s >> k;
	if(k == 0) {
		cout << "1\n";
		return 0;
	}
	pre();

	vector <int> r;
	dp[1] = 0;
	if(k == 1)
		r.push_back(1);
	for(int i = 2; i <= 1000; i++) {
		dp[i] = dp[__builtin_popcount(i)] + 1;
		if(dp[i] == k - 1)
			r.push_back(i);
	}
	int ans = 0;
	dbg(r);
	for(auto i : r)
		ans = (ans + get(i)) % MOD;
	if(k == 1) ans--;
	cout << ans << '\n';

}