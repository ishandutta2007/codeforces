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

	int g=0, t=0;
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i=0; i<n; i++)
		if (s[i] == 'G')
			g = i;
		else if (s[i] == 'T')
			t = i;
	while (g < t) {
		if (g+k < n && s[g+k] != '#')
			g += k;
		else break;
	}
	while (g > t) {
		if (g-k >= 0 && s[g-k] != '#')
			g -= k;
		else break;
	}
	cout << (g == t ? "YES\n" : "NO\n");
}