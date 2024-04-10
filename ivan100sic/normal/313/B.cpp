#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
int n, q;
int z[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	s = string(" ") + s;
	for (int i=1; i<n; i++)
		z[i] = z[i-1] + (s[i] == s[i+1]);
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << z[r-1] - z[l-1] << '\n';
	}
}