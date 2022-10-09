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

	int i = 0, j = n-1;
	while (i+1 < n && s[i] == s[i+1])
		i++;
	while (j-1 >= 0 && s[j] == s[j-1])
		j--;

	if (s[i] != s[j]) {
		cout << i+n-j+2 << '\n';
	} else {
		cout << (i+2) * 1ll * (n-j+1) % 998244353 << '\n';
	}
}