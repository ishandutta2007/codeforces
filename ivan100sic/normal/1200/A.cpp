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
	string a(10, '0');
	for (char x : s) {
		if (x == 'L') {
			for (int i=0; i<10; i++)
				if (a[i] == '0') {
					a[i] = '1';
					break;
				}
		} else if (x == 'R') {
			for (int i=9; i>=0; i--)
				if (a[i] == '0') {
					a[i] = '1';
					break;
				}
		} else {
			a[x - '0'] = '0';
		}
	}
	cout << a << '\n';
}