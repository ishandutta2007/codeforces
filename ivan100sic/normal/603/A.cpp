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
	int a = 0, b = 0;
	for (int i=0; i<n-1; i++) {
		if (s[i] != s[i+1]) {
			a++;
		} else {
			b++;
		}
	}
	cout << 1 + a + min(2, b) << '\n';
}