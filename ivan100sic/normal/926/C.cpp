#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], z[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		z[i+1] = z[i] + a[i];
	}
	
	for (int d=1; d<=n; d++) {
		if (n % d)
			continue;
		int e = -1, ok = 1;
		for (int j=0; j<n; j+=d) {
			int x = z[j+d] - z[j];
			if (x != 0 && x != d)
				ok = 0;
			if (e == -1) {
				e = d-x;
			} else if (e != x) {
				ok = 0;
			} else {
				e = d-x;
			}
		}
		if (ok) {
			cout << "YES\n";
			return 0;
		}
	}	
	
	cout << "NO\n";
}