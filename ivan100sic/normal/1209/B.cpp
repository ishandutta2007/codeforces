#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a[105], b[105];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=0; i<n; i++)
		cin >> a[i] >> b[i];

	int z = 0;
	for (int t=0; t<120*120; t++) {
		int v = 0;
		for (int i=0; i<n; i++) {
			int u = s[i] == '1';
			if (t >= b[i])
				u ^= (t - b[i]) / a[i] % 2, u ^= 1;
			v += u; 
		}
		z = max(z, v);
	}
	cout << z << '\n';
}