#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int a[200009];
bool vs[200009];
vector<int> rv, pr;
vector<vector<long long> > v;
multiset<long long> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= 200000; i++) {
		if (vs[i]) continue;
		pr.push_back(i);
		for (int j = i; j <= 200000; j += i)
			vs[j] = true;
	}
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, q; cin >> n >> q;
		for (int i = 0; i < v.size(); i++)
			v[i].clear();
		rv.clear(); v.clear();
		st.clear();
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < pr.size() && pr[i] <= n; i++) {
			if (n % pr[i] == 0) {
				int tr = n / pr[i];
				rv.push_back(tr);
				v.push_back(vector<long long>(tr, 0));
				for (int j = 0; j < tr; j++) {
					for (int pi = j; pi < n; pi += tr)
						v.back()[j] += a[pi];
					st.insert(v.back()[j] * tr);
				}
			}
		}
		cout << *(--st.end()) << '\n';
		for (int i = 0; i < q; i++) {
			int p, x; cin >> p >> x; p--;
			int dx = x - a[p]; a[p] = x;
			for (int j = 0; j < rv.size(); j++) {
				int t = p % rv[j];
				st.erase(st.find(v[j][t] * rv[j]));
				v[j][t] += dx;
				st.insert(v[j][t] * rv[j]);
			}
			cout << *(--st.end()) << '\n';
		}
	}
	return 0;
}