#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
int n;
int a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	for (int i=1; i<=n; i++) {
		if (s[i-1] == 'a') {
			a[i-1] ^= 1;
			reverse(s.begin(), s.begin() + (i-1));
			a[i] ^= 1;
			reverse(s.begin(), s.begin() + i);
		}
	}

	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}