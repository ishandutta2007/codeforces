#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long  _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 
#define y1 y2353462
using namespace std;

long long  n, k, v, m, nrel, nrst, x1, y1, x2, y2, q, x;

vector <long long > el, st;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

long long  solve(long long  x1, long long  y1, long long  x2, long long  y2) {

		long long  dh = abs(x2 - x1);
		if(dh == 0) return abs(y1 - y2);
		// elevator
		long long ans = 1e18;
		auto it = lower_bound(el.begin(), el.end(), min(y1, y2));
		auto it2 = it;
		it2--;
		// dbg(*it);
		// dbg(*it2);
		ans = min(ans, abs(y1 - *it) + (dh + v - 1) / v + abs(*it - y2));
		ans = min(ans, abs(y1 - *it2) + (dh + v - 1) / v + abs(*it2 - y2));
		// dbg(ans);
		//stairs

		it = lower_bound(st.begin(), st.end(), min(y1, y2));
		it2 = it;
		it2--;
		ans = min(ans, abs(y1 - *it) + dh + abs(*it - y2));
		ans = min(ans, abs(y1 - *it2) + dh + abs(*it2 - y2));
		// dbg(ans);
		return ans;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> nrst >> nrel >> v;
 
	for(long long  i = 0; i < nrst; i++) cin >> x, st.push_back(x);
	for(long long  i = 0; i < nrel; i++) cin >> x, el.push_back(x);

	el.push_back(-1000000000);
	el.push_back(1000000000);
	st.push_back(-1000000000);
	st.push_back(1000000000);
	sort(el.begin(), el.end());
	sort(st.begin(), st.end());

	cin >> q;
	for(long long  i = 1; i <= q; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << solve(x1, y1, x2, y2) << '\n';
	}

}