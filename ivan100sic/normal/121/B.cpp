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

	int n, k;
	string s;
	cin >> n >> k >> s;
	for (int i=0; i<n && k>0; i++) {
		if (s[i] == '4' && i+1 < n && s[i+1] == '7') {
			if (i % 2 == 1 && i > 0 && s[i-1] == '4' && k > 1) {
				k %= 2;
				i = -1;
			} else if (i % 2 == 0 && i+2 < n && s[i+2] == '7' && k > 1) {
				k %= 2;
				i = -1;
			} else if (i % 2 == 1) {
				s[i] = '7';
				k--;
			} else {
				s[i+1] = '4';
				k--;
			}
		}
	}
	cout << s << '\n';
}