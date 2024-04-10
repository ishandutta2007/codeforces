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

	string s, a;
	cin >> s;
	int n = s.size();
	int l = 0, r = n-1;
	while (r-l > 2) {
		char x;
		if (s[l] == s[r] || s[l] == s[r-1])
			x = s[l];
		else
			x = s[l+1];
		a += x;
		l += 2, r -= 2;
	}
	cout << a;
	if (l <= r)
		cout << s[l];
	reverse(a.begin(), a.end());
	cout << a << '\n';
}