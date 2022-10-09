#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		map<int, int> mp;
		int n;
		cin >> n;
		while (n--) {
			int x;
			cin >> x;
			mp[x]++;
		}

		vector<int> v;
		for (auto p : mp) {
			if (p.second >= 2)
				v.push_back(p.first);
			if (p.second >= 4)
				v.push_back(p.first);
		}

		double radi = 1e30;
		int ax = -1, bx = -1;

		for (int i=0; i<(int)v.size()-1; i++) {
			int a = v[i];
			int b = v[i+1];

			double ratio = (a+b)*(a+b) * 1.0 / a / b;

			if (ratio < radi) {
				radi = ratio;
				ax = a;
				bx = b;
			}
		}

		cout << ax << ' ' << bx << ' ' << bx << ' ' << ax << '\n';
	}
}