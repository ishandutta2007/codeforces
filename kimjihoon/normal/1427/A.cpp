#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int s1 = 0, s2 = 0;
		v[0].clear(); v[1].clear(); v[2].clear();
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (a > 0) {
				s1 += a;
				v[1].push_back(a);
			}
			else if (a < 0) {
				s2 -= a;
				v[2].push_back(a);
			}
			else
				v[0].push_back(a);
		}
		int t = 1;
		if (s1 == s2) {
			cout << "NO" << '\n';
			continue;
		}
		if (s2 > s1) t = 2;
		cout << "YES" << '\n';
		for (int i = 0; i < v[t].size(); i++) cout << v[t][i] << " ";
		for (int i = 0; i < v[3 - t].size(); i++) cout << v[3 - t][i] << " ";
		for (int i = 0; i < v[0].size(); i++) cout << v[0][i] << " ";
		cout << '\n';
	}
	return 0;
}