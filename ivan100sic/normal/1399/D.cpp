// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int l = 0;
		vector<int> a[2], b(n);
		for (int i=0; i<n; i++) {
			int x = s[i] - '0';
			if (a[1-x].size()) {
				int s = a[1-x].back();
				a[1-x].pop_back();
				a[x].push_back(s);
				b[i] = s;
			} else {
				a[x].push_back(++l);
				b[i] = l;
			}
		}

		cout << l << '\n';
		for (int i=0; i<n; i++) {
			cout << b[i] << " \n"[i == n-1];
		}
	}
}