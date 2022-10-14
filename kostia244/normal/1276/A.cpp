#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	string s;
	cin >> s;
	vi x(s.size());
	vi ans;
	for(int i = 0; i + 4 < s.size(); i++) {
		if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]=='e')
			ans.pb(i+2),x[i+2]=1;
	}
	for(int i = 0; i+2 < s.size(); i++) {
		if(x[i+2]||x[i]) continue;
		if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
			ans.pb(i+1);
		if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
			ans.pb(i+1);
	}
	cout << ans.size() << "\n";
	for(auto i : ans) cout << i+1 << " ";cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}