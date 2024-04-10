#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[2009];
vector<pair<int, int> > ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	cout << "? " << 1 << endl;
	int s[2] = { 0, 0 };
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		v[a].push_back(i);
		s[a & 1]++;
		if (a == 1)
			ans.push_back(make_pair(1, i));
	}
	int t = 2;
	if (s[0] > s[1]) t = 1;
	for (int i = t; i <= n; i += 2) {
		for (int j = 0; j < v[i].size(); j++) {
			int hn = v[i][j];
			cout << "? " << hn << endl;
			for (int pi = 1; pi <= n; pi++) {
				int a; cin >> a;
				if (pi != 1 && a == 1)
					ans.push_back(make_pair(hn, pi));
			}
		}
	}
	cout << "!" << endl;
	for (int i = 0; i < n - 1; i++)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}