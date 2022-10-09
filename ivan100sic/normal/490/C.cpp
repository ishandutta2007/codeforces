#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ar[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	int a, b;
	cin >> a >> b;
	ar[0] = 0;
	for (int i=0; i<n; i++) {
		ar[i+1] = (ar[i] * 10 + s[i] - '0') % a;
	}
	int q = 0, p = 1;
	for (int i=n-1; i>0; i--) {
		q = (q + p * 1ll * (s[i] - '0')) % b;
		p = p * 10 % b;
		if (q == 0 && ar[i] == 0 && s[0] != '0' && s[i] != '0') {
			cout << "YES\n";
			cout << s.substr(0, i) << '\n' << s.substr(i) << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}