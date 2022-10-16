#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, a;
vector <pair<int, int> > v;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)	{
		cin >> a;
		v.push_back({a, i});
	}

	sort(v.begin(), v.end());

	set<pair<int, int> > s;
	s.insert({-2, -1});
	s.insert({1e9+100, 1e9+123});
	int maxsz = 0, nr = 0, ans, ansmax = 0;

	for(int i = 0; i < v.size(); i++) {
		auto p = v[i];
		// dbg_p(p);
		nr++;
		auto it = s.upper_bound({p.second, 0});

		if(it != s.end()) {

			if(it->first == p.second + 1) {
				int right = it->second;
				int left = p.second;
				auto it2 = it;
				it2--;
				if(it2->second == p.second - 1) {
					left = it2->first;
					s.erase(*it2);
				}
				s.erase(*it);
				s.insert({left, right});
				maxsz = max(maxsz, right - left + 1);
			}
			else {
				int right = p.second;
				int left = p.second;
				it--;
				if(it->second == p.second - 1) {
					left = it->first;
					s.erase(*it);
				}
				s.insert({left, right});
				maxsz = max(maxsz, right - left + 1);
			}
		}

		if(nr % ((int)s.size() - 2) == 0 && 1ll * ((int)s.size() - 2) * maxsz == 1ll * nr) {
			if(ansmax < ((int)s.size() - 2))
				ans = v[i].first, 
				ansmax = ((int)s.size() - 2);
		}
	}

	cout << ans + 1 << '\n';
}