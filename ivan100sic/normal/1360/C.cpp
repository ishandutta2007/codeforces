// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[55];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> a[i];

		sort(a, a+n);

		bool ok = false;
		for (int i=0; i<n-1; i++)
			if (a[i+1] - a[i] == 1)
				ok = true;

		int o=0, e=0;
		for (int i=0; i<n; i++)
			(a[i] % 2 ? o : e)++;

		if (o % 2 == 0)
			ok = true;

		cout << (ok ? "yes\n" : "no\n");
	}
}