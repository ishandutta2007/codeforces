#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.size(); i++)
		for(int j = 0; j <= s.size(); j++) {
			string t, f;
			t = f = s.substr(i, j);
			reverse(all(f));
			if(t != f) ans = max(ans, (int)t.size());
		}
	cout << ans << '\n';
}