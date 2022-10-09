#include <bits/stdc++.h>
using namespace std;

int n, m;
string a[5005];
vector<string> b;

bool imadvaista = false;

void probaj(int i, int j) {
	string ref = b[0];
	swap(ref[i], ref[j]);

	for (string& p : b) {
		int d = 0;
		for (int k=0; k<m; k++) {
			if (p[k] != ref[k]) {
				d++;
			}
		}
		if (d > 2) {
			return;
		}
		if (d == 0) {
			if (!imadvaista) {
				return;
			}
		}
	}

	cout << ref << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	string s = a[0];
	sort(s.begin(), s.end());
	for (int i=0; i<n; i++) {
		string p = a[i];
		sort(p.begin(), p.end());
		if (p != s) {
			cout << -1;
			return 0;
		}
	}

	b = vector<string>(a, a+n);
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());

	if (b.size() == 1) {
		swap(b[0][0], b[0][1]);
		cout << b[0];
		return 0;
	}

	if (m > 26) {
		imadvaista = true;
	} else {
		for (int i=0; i<m; i++) {
			for (int j=i+1; j<m; j++) {
				if (s[i] == s[j]) {
					imadvaista = true;
				}
			}
		}
	}

	vector<int> kand;
	// razlike
	for (int i=0; i<m; i++) {
		if (b[0][i] != b[1][i]) {
			kand.push_back(i);
		}
	}

	if (kand.size() > 4) {
		cout << -1;
		return 0;
	}

	for (int i : kand) {
		for (int j=0; j<m; j++) {
			probaj(i, j);
		}
	}

	cout << -1;
}