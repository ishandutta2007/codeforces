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
		vector<int> a(n);
		for (int& x : a) cin >> x;
		queue<int> q;
		q.push(1);
		vector<int> d(n+1);
		for (int i=1; i<n; i++) {
			int j = i;
			while (j+1 < n && a[j] < a[j+1]) {
				j++;
			}

			// sve do j kaci na sledeceg
			int p = q.front(); q.pop();
			for (int u=i; u<=j; u++) {
				int x = a[u];
				d[x] = d[p] + 1;
				q.push(x);
			}

			i = j;
		}

		cout << *max_element(begin(d), end(d)) << '\n';
	}
}