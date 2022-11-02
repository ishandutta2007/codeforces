#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[109];
vector<pair<int, int> > ans;

void ep(int vi, int r)
{
	if (v[vi].size() <= r) return;
	for (int i = 0; i < v[vi].size(); i += r * 2)
		for (int j = 0; j < r; j++)
			ans.push_back(make_pair(v[vi][i + j], v[vi][i + j + r]));
	ep(vi, r * 2);
}

void pn(int a, int b, int r)
{
	for (int i = 1; i <= r; i++) 
		ans.push_back(make_pair(v[a][(int)v[a].size() - i], v[b][(int)v[b].size() - i]));
	for (int i = 0; i < r; i++) {
		v[b].push_back(v[a].back());
		v[a].pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int c = 0, ml = 0;
	for (int i = 0; i < 20; i++)
		if (n & (1 << i)) {
			ml = i;
			for (int j = 0; j < (1 << i); j++) {
				c++;
				v[i].push_back(c);
			}
			ep(i, 1);
		}
	for (int i = 1; i < ml; i++) {
		if ((1 << i) > v[i - 1].size()) pn(ml, i - 1, (int)v[i - 1].size());
		while (!v[i - 1].empty()) {
			v[i].push_back(v[i - 1].back());
			v[i - 1].pop_back();
		}
		if (v[i].size() > (1 << i)) 
			ep(i, v[i].size() / 2);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << '\n';
	return 0;
}