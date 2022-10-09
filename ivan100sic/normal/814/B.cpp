#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int b[1005];

int p[1005];

vector<int> f[1005];

void proveri() {
	int df = 0;
	for (int i=1; i<=n; i++) {
		if (b[i] != p[i]) {
			df++;
		}
	}
	if (df == 1) {
		for (int i=1; i<=n; i++) {
			cout << p[i] << ' ';
		}
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}

	for (int i=1; i<=n; i++) {
		f[a[i]].push_back(i);
	}

	int j = 0, k = 0;
	for (int i=1; i<=n; i++) {
		if (f[i].size() == 2) {
			j = i;
		}
		if (f[i].size() == 0) {
			k = i;
		}
	}

	cerr << j << ' ' << k << '\n';

	copy(a, a+n+1, p);

	p[f[j][0]] = k;
	proveri();

	copy(a, a+n+1, p);


	p[f[j][1]] = k;
	proveri();
}