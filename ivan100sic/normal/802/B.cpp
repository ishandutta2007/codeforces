#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[400005];
int seen[400005], nx[400005];
int c[400005], u[400005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	memset(seen, 63, sizeof seen);
	for (int i=n-1; i>=0; i--) {
		nx[i] = seen[a[i]];
		u[a[i]] = seen[a[i]] = i;
	}

	set<pair<int, int>> q;
	int sol = 0;

	for (int i=0; i<n; i++) {
		bool ima = q.count({u[a[i]], a[i]});
		if (ima) {
			q.erase({u[a[i]], a[i]});
			u[a[i]] = nx[i];
			q.insert({u[a[i]], a[i]});
		} else {
			u[a[i]] = nx[i];
			if ((int)q.size() == k) {
				auto it = --q.end();
				q.erase(it);
			}
			sol++;
			q.insert({u[a[i]], a[i]});
		}
	}

	cout << sol << '\n';
}