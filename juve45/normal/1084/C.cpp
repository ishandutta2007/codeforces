#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

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

const int N = 100100;
const int MOD = 1e9 + 7;
int n, k, m, nr, dp[N];
vector <int> v;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	for(auto i : s) 
		if(i == 'a') nr++;
		else if(i == 'b') v.push_back(nr), nr = 0;

	if(nr) v.push_back(nr);
	long long ans = 0;
	// dbg(v);
	for(int i = 0; i < v.size(); i++) {
		ans = ans * (1LL + v[i]) + 1LL * v[i];
		ans %= MOD;
	}
	cout << ans << '\n';


}