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
	int a1 = 0;
	int a2 = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0 && s[i] != 'r') {
			a1++;
		}
		if (i % 2 == 1 && s[i] == 'r') {
			a2++;
		}
	}
	ans = max(a1, a2);
	a1 = 0;
	a2 = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 1 && s[i] != 'r') {
			a1++;
		}
		if (i % 2 == 0 && s[i] == 'r') {
			a2++;
		}
	}

	ans = min(ans, max(a1, a2));
	cout << ans;
}