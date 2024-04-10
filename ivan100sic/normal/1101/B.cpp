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

	string s;
	cin >> s;
	int n = s.size();

	int a = -1, b = -1;
	for (int i=0; i<n; i++) {
		if (a == -1 && s[i] == '[')
			a = i;
		if (s[i] == ']')
			b = i;
	}
	if (a == -1 || b == -1)
		return cout << "-1\n", 0;

	int c = -1, d = -1;
	for (int i=a+1; i<b; i++) {
		if (s[i] == ':') {
			if (c == -1)
				c = i;
			d = i;
		}
	}

	if (c == d || c == -1)
		return cout << "-1\n", 0;

	cout << 4 + count(s.begin()+c+1, s.begin()+d, '|') << '\n';
}