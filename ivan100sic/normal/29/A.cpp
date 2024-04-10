#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int x[105], d[105], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> x[i] >> d[i];
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++) {
			if (x[i] == x[j] + d[j] && x[j] == x[i] + d[i]) {
				cout << "YES\n";
				return 0;
			}
		}
	cout << "NO\n";
}