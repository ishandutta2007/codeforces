// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll n, p;
	cin >> n >> p;
	vector<int> a(n);
	for (ll i=0; i<n; i++) {
		string s;
		cin >> s;
		a[i] = s.size() == 4;
	}
	ll j = 0, z = 0;
	for (int i=n-1; i>=0; i--) {
		if (a[i])
			j *= 2;
		else
			j = 2*j+1;
		z += j*p/2;
	}
	cout << z << '\n';
}