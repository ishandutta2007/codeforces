// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++)
			cin >> a[i];
		set<int> s;
		string f(n+1, 0), b(n+1, 0);
		f[0] = b[0] = 1;
		for (int i=0; i<n; i++) {
			s.insert(a[i]);
			if ((int)s.size() == i+1 && *s.rbegin() == i+1) {
				f[i+1] = 1;
			}
		}
		s = {};
		for (int i=0; i<n; i++) {
			s.insert(a[n-i-1]);
			if ((int)s.size() == i+1 && *s.rbegin() == i+1) {
				b[i+1] = 1;
			}
		}
		vector<int> sol;
		for (int i=1; i<n; i++) {
			if (f[i] && b[n-i]) {
				sol.push_back(i);
			}
		}
		cout << sol.size() << '\n';
		for (int x : sol)
			cout << x << ' ' << n-x << '\n';
	}	
}

// I will still practice daily...