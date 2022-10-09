#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[30];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	if (__builtin_popcount(n) > k || k > n)
		return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i=0; i<30; i++)
		if (n & (1 << i))
			c[i]++, k--;
	for (int i=29; i>0; i--)
		while (k > 0 && c[i] > 0)
			c[i]--, c[i-1] += 2, k--;
	for (int i=0; i<30; i++)
		while (c[i]--)
			cout << (1 << i) << ' ';
	cout << '\n';
}