#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], n;
map<int, vector<int>> e;
int gr[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		e[a[i]].push_back(i);
	}

	int g = 0;
	vector<int> sh;

	for (auto& [x, v] : e) {
		if (v.size() >= 2) {
			gr[v[0]] = 1;
			for (int i=1; i<(int)v.size(); i++)
				gr[v[i]] = 2;
			g = gcd(g, x);
		} else {
			sh.push_back(v[0]);
		}
	}

	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
		+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

	int k = sh.size();
	for (int i=0; i<2000000/max(k, 1); i++) {
		shuffle(sh.begin(), sh.end(), eng);
		int g1 = g, g2 = g;
		for (int j=0; j<k; j++) {
			if (g1 != 1) {
				g1 = gcd(g1, a[sh[j]]);
				gr[sh[j]] = 1;
			} else {
				g2 = gcd(g2, a[sh[j]]);
				gr[sh[j]] = 2;
			}
		}

		// cerr << "try " << i << ' ' << g1 << ' ' << g2 << '\n';

		if (g1 == 1 && g2 == 1) {
			cout << "YES\n";
			for (int i=0; i<n; i++)
				cout << gr[i] << " \n"[i == n-1];
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}