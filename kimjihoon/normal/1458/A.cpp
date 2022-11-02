#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

long long a[200009];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0 && a[0] > a[i]) swap(a[0], a[i]);
	}
	long long s = 0;
	for (int i = 1; i < n; i++) {
		a[i] -= a[0];
		s = gcd(s, a[i]);
	}
	for (int i = 0; i < m; i++) {
		long long b; cin >> b;
		cout << gcd(s, a[0] + b) << " ";
	}
	cout << '\n';
	return 0;
}