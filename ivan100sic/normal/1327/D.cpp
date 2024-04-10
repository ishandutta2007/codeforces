// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> divs[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int x=1; x<=200000; x++)
		for (int y=x; y<=200000; y+=x)
			divs[y] += x;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n), c(n), u(n);
		for (int i=0; i<n; i++)
			cin >> p[i], p[i]--;
		for (int i=0; i<n; i++)
			cin >> c[i];

		int sol = n;
		for (int i=0; i<n; i++) {
			if (!u[i]) {
				vector<int> d;
				for (int j=p[i]; j!=i; j=p[j])
					d.push_back(c[j]), u[j] = 1;
				d.push_back(c[i]);
				u[i] = 1;
				int m = d.size();
				for (int x : divs[m]) {
					for (int r=0; r<x; r++) {
						int cl = -1, br = 0;
						for (int i=r; i<m; i+=x)
							if (d[i] != cl)
								cl = d[i], br++;
						if (br == 1) {
							sol = min(sol, x);
						}
					}
				}
			}
		}

		cout << sol << '\n';
	}
}

// I will still practice daily...