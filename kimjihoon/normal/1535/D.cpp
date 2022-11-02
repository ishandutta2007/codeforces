#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, c[1000009];
string s;

void update(int i)
{
	if (i * 2 > n - 1	) {
		if (s[i] == '?') c[i] = 2;
		else c[i] = 1;
	}
	else {
		if (s[i] == '?') c[i] = c[i * 2] + c[i * 2 + 1];
		else if (s[i] == '0') c[i] = c[i * 2 + 1];
		else c[i] = c[i * 2];
	}
	if (i > 1) update(i / 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k; cin >> k;
	n = (1 << k);
	cin >> s; s += "0";
	reverse(s.begin(), s.end());
	for (int i = n - 1; i >= 1; i--) {
		if (i * 2 > n - 1) {
			if (s[i] == '?') c[i] = 2;
			else c[i] = 1;
			continue;
		}
		if (s[i] == '?') c[i] = c[i * 2] + c[i * 2 + 1];
		else if (s[i] == '0') c[i] = c[i * 2 + 1];
		else c[i] = c[i * 2];
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int a; char t; cin >> a >> t;
		a = n - a;
		s[a] = t;
		update(a);
		cout << c[1] << '\n';
	}
	return 0;
}