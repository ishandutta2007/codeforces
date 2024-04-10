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

	int n, k; string s;
	cin >> n >> k >> s;
	int w=0, r=0;
	for (int i=0; i<n; i++) {
		if (s[i] == '#')
			r++;
		else
			r = 0;
		w = max(w, r);
	}
	cout << (w < k ? "YES\n" : "NO\n");
}