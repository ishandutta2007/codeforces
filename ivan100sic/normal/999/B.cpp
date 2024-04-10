#include <bits/stdc++.h>
using namespace std;

int p[105], q[105], n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	iota(p, p+n, 0);
	for (int i=n; i>=1; i--) {
		if (n % i == 0)
			reverse(p, p+i);
	}
	for (int i=0; i<n; i++)
		q[p[i]] = i;
	for (int i=0; i<n; i++)
		cout << s[q[i]];
	cout << '\n';
}