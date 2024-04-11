#include <bits/stdc++.h>
using namespace std;

long long n, i;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;

	long long c1 = 1;
	for (i = 1; i < n, s[i - 1] == s[i]; i++)
		;
	c1 = i;

	long long c = 1;
	for (i = n - 2; i >= 0, s[i] == s[i + 1]; i--)
		c++;


	if(c1 == n) {
		cout << (((c1 * (c1 + 1))/2)  % 998244353);
	} else if(s[0] == s[n - 1]) {
		cout << (((c1+1) * (c + 1)) % 998244353);
	} else {
		cout << ((c + c1 + 1) % 998244353);
	}
}