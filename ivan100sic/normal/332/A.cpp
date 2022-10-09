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

	int n, z=0;
	string s;
	cin >> n >> s;
	int m = s.size();
	for (int i=n; i<m; i+=n) {
		if (s[i-3] == s[i-2] && s[i-2] == s[i-1]) {
			z++;
		}
	}
	cout << z << '\n';
}