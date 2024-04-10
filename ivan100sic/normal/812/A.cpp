#include <bits/stdc++.h>
using namespace std;

int a[10][10];
int l[10], s[10], r[10], p[10];
int g[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<4; i++) {
		cin >> l[i] >> s[i] >> r[i] >> p[i];
		g[i] += l[i] + s[i] + r[i];

		g[(i+1) % 4] += r[i];
		g[(i+2) % 4] += s[i];
		g[(i+3) % 4] += l[i];
	}

	for (int i=0; i<4; i++) {
		if (p[i] && g[i]) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";


}