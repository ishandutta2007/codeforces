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

int n, k, m, ans, x, y, l, r;
const int MOD = 1e9 + 7;

priority_queue <int> pq;
vector <pair<int, int > > v; 

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> x >> y;

	for(int i = 1; i <= n; i++) {
		cin >> l >> r;
		
		ans += (1LL * (r - l + 1) * y) % MOD;
		ans %= MOD;

		v.push_back({l, 1});
		v.push_back({r + 1, -1});
	}

	sort(v.begin(), v.end());

	for(auto e : v) {
		if(e.nd == 1) {

			if(pq.empty()) {
				ans += x - y;
				ans %= MOD;
				continue;
			}

			int best = pq.top();
			int dist = e.st - best;
			if((1LL * dist * y + y) < 1LL *  x) {
				pq.pop();
				ans += (1LL * dist * y) % MOD;
				ans %= MOD;
			}
			else {
				ans += x - y;
				ans %= MOD;
			}

		} else {
			pq.push(e.st);
		}
	}
	cout << ans << '\n';
}