#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

vector<vector<int>> cycles() {
	string v(n+1, 0);
	vector<vector<int>> z;
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			vector<int> s = {i};
			v[i] = 1;
			for (int j=a[i]; j!=i; j=a[j])
				v[j] = 1, s.push_back(j);
			z.push_back(s);
		}
	}

	sort(z.begin(), z.end(), [&](const auto& u, const auto& v) {
		return u.size() < v.size();
	});

	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	auto cyc = cycles();

	if (cyc[0].size() == 1) {
		int fp = cyc[0][0];
		cout << "YES\n";
		for (int i=1; i<=n; i++)
			if (i != fp)
				cout << i << ' ' << fp << '\n';
		return 0;
	}

	if (cyc[0].size() == 2) {
		vector<vector<int>> parni, neparni;
		for (int i=1; i<(int)cyc.size(); i++) {
			if (cyc[i].size() % 2)
				neparni.push_back(cyc[i]);
			else
				parni.push_back(cyc[i]);
		}

		if (neparni.size()) {
			cout << "NO\n";
			return 0;
		}

		cout << "YES\n";
		int p = cyc[0][0], q = cyc[0][1];
		cout << p << ' ' << q << '\n';
		for (auto v : parni) {
			for (int i=0; i<(int)v.size(); i+=2) {
				cout << p << ' ' << v[i] << '\n';
				cout << q << ' ' << v[i+1] << '\n';
			}
		}
		
		return 0;
	}

	cout << "NO\n";
}