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

	int t;
	cin >> t;
	while (t--) {
		string s;
		int n;
		cin >> n >> s;
		int l = 0, r = 0;
		while (l < n && s[l] == '<')
			l++;
		while (r < n && s[n-r-1] == '>')
			r++;
		cout << min(l, r) << '\n';
	}
}