// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[1000005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int x = find(a, a+n, -1) - a;
	rotate(a+x, a+x+1, a+n);
	fill(a, a+x, 0);

	ll sol = 0;
	multiset<int> s;

	int r = n-2;
	for (int j=n/2; j>=1; j/=2) {
		s.insert(a[r]);
		sol += *s.begin();
		s.erase(s.begin());
		for (int i=r-j+1; i<r; i++)
			s.insert(a[i]);
		r -= j;
	}

	cout << sol << '\n';
}