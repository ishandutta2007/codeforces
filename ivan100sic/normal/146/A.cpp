#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	int x = count(s.begin(), s.end(), '4');
	x += count(s.begin(), s.end(), '7');

	int y = 0;
	for (int i=0; i<n; i++) {
		if (i < n/2)
			y += s[i];
		else
			y -= s[i];
	}

	cout << (x == n && y == 0 ? "YES\n" : "NO\n");
}