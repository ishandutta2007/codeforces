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
	cin >> n;
	string s;
	cin >> s;
	int a=0, b=0, c=0, d=0;
	for (int i=0; i<n; i++) {
		if (i % 2) {
			if (s[i] == '0')
				a++;
			else
				b++;
		} else {
			if (s[i] == '0')
				c++;
			else
				d++;
		}
	}
	cout << n - max(a+d, b+c) << '\n';
}