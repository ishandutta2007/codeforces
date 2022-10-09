// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[200005];
ll s;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[x] = i;
	}

	for (int i=1; i<n; i++) {
		s += abs(a[i+1] - a[i]);
	}

	cout << s << '\n';
}