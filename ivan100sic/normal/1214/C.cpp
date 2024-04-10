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

	int n, s=0, d=0;
	string a;
	cin >> n >> a;
	for (char x : a) {
		if (x == '(') {
			s++;
		} else {
			s--;
		}
		d = min(d, s);
	}
	cout << (s == 0 && d >= -1 ? "Yes\n" : "No\n");
}