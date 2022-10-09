#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
valarray<int> a[105], b;
int f[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		a[i].resize(n);
		for (int j=0; j<n; j++)
			a[i][j] = s[j] - '0';
	}
	b.resize(n);
	for (int i=0; i<n; i++)
		cin >> b[i];
	b *= -1;
	while (1) {
		int i = -1;
		for (int j=0; j<n; j++)
			if (b[j] == 0) {
				i = j;
				break;
			}
		if (i == -1)
			break;
		b += a[i] * (1 - 2*f[i]);
		f[i] ^= 1;
	}

	vector<int> z;
	for (int i=0; i<n; i++)
		if (f[i])
			z.push_back(i+1);
	sort(z.begin(), z.end());
	cout << z.size() << '\n';
	for (int x : z)
		cout << x << ' ';
	cout << '\n';
}