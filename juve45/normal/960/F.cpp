#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<(x).first<<","<<(x).second<<"  "
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 100100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, m, a, b, c, ans;

set<pair<int, int> > dp[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		// a - > b
		// dbg(a);
		// for(auto i : dp[a]) dbg_p(i);
		// 	cerr << '\n';
		// dbg(b);
		// for(auto i : dp[b]) dbg_p(i);
		// 	cerr << '\n';

		auto it = dp[a].lower_bound({c, -1});

		int l;
		if(it == dp[a].begin()) {
			// dbg_ok; 	
			l = 1;
		}
		else {
			it--;
			l = it->nd + 1;
		}
		ans = max(ans, l);
		dp[b].insert({c, l});
		it = dp[b].find({c, l});
		auto it1 = it;
		if(it != dp[b].begin()) {
			it1--;
			if(it1->nd >= it->nd) {
				dp[b].erase({c, l});
				continue;
			}
		}


		while(true) {
			auto it1 = dp[b].find({c, l});
			if(it1 == dp[b].end()) 
				break;
			it1++;
			if(it1 == dp[b].end())
				break;
			if(it1->nd <= it->nd)
				dp[b].erase(*it1);
			else break;
		}
	}

	cout << ans << '\n';
}