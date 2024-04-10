#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int> > v[2];
bool vs[109][109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			v[(i + j) % 2].push_back(make_pair(i, j));
	int f = 0, pi = 1, pj = 1;
	for (int i = 0; i < n * n; i++) {
		int a; cin >> a;
		if (f) {
			while (vs[pi][pj]) {
				pj++;
				if (pj == n + 1) {
					pi++; pj = 1;
				}
			}
			vs[pi][pj] = true;
			int t = 1;
			while (t == f || t == a)
				t++;
			cout << t << " " << pi << " " << pj << endl;
		}
		else {
			int r = 0;
			if (a == 1) r = 1;
			int ri = v[r].back().first, rj = v[r].back().second;
			v[r].pop_back();
			cout << r + 1 << " " << ri << " " << rj << endl;
			vs[ri][rj] = true;
			if (v[r].empty()) 
				f = r + 1;
		}
	}
	return 0;
}