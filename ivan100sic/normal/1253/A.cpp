#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> a[i];
		for (int i=0; i<n; i++)
			cin >> b[i];

		int u = 0, v = 0;
		while (u < n && a[u] == b[u])
			u++;
		while (v < n && a[n-1-v] == b[n-1-v])
			v++;
		
		if (u+v >= n) {
			cout << "YES\n";
		} else {
			set<int> s;
			for (int j=u; j<n-v; j++)
				s.insert(b[j] - a[j]);
			if (s.size() == 1 && *s.begin() > 0) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}