#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e6 + 55;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, s = 0;
	vi a;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i, s += i;
	map<int, pair<int, int>> pos;
	map<pair<int, int>,int> val;
	vi ans;
	vector<pair<pair<int, int>, pair<int, int>>> op;
	for(int i = 0; i < n; i++) {
		for(int t, j = 0; j < a[i]; j++) {
			cin >> t;
			ans.push_back(t);
			pos[t] = {i+1, j+1};
			val[{i+1, j+1}] = t;
		}
	}
	sort(ans.begin(), ans.end());
	int q = 0, x = 1, y = 1;
	for(int i = 0; i < s; i++) {
		if(ans[i] != val[{x, y}]) {
			pair<int, int> p1 = {x, y}, p2 = pos[ans[i]];
			op.push_back({p1, p2});
			int cur = val[{x, y}];
			swap(pos[ans[i]], pos[cur]);
			swap(val[p1], val[p2]);
		}

		if(y==a[q]) {
			x++, q++;
			y = 1;
		} else {
			y++;
		}
	}
	cout << op.size() << "\n";
	for(auto i : op) cout << i.first.first << " " << i.first.second << " " << i.second.first << " " << i.second.second << "\n";
}