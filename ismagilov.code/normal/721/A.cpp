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
	vc<int> ans;
	int tek = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') {
			tek++;
		}
		else {
			if (tek > 0) {
				ans.pb(tek);
			}
			tek = 0;
		}
	}

	if (tek > 0) {
		ans.pb(tek);
	}
	tek = 0;
	cout << ans.size() << endl;
	for (auto i : ans){
		cout << i << ' ';
	}
}