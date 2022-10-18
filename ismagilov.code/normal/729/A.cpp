#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int i;
	for (i = 0; i + 2 < n; i++) {
		if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
			cout << "***";
			int j = i;
			i += 3;
			for (; i + 1 < n && ((i % 2 != j % 2 && s[i] == 'g') && (s[i + 1] == 'o')); i += 2) {
			}
			i--;
		}
		else {
			cout << s[i];
		}
	}
	for (; i < n; i++) {
		cout << s[i];
	}
}