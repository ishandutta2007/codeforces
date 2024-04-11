#pragma GCC optimize("trapv")
#pragma GCC target("avx,avx2,ssse3,sse2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
vector<vi> g;
void solve() {
	string s;
	cin >> s;
	g.assign(26, {});
	for(int i = 1; i < s.size(); i++) {
		g[s[i]-'a'].pb(s[i-1]-'a');
		g[s[i-1]-'a'].pb(s[i]-'a');
	}
	for(auto &i : g) {
		sort(all(i));
		i.erase(unique(all(i)), i.end());
		if(i.size()>2) {
			cout << "NO\n";
			return;
		}
	}
	int st = -1;
	string ans;
	for(int i = 0; i < 26; i++) {
		if(g[i].size()==1) st = i;
		if(g[i].empty()) ans.pb(i+'a');
	}
	bitset<26> vis;
	int p = -1;
	while(st!=-1) {
		vis[st] = 1;
		ans.pb(st+'a');
		if(g[st].back()==p)
			g[st].pop_back();
		if(g[st].empty()) break;
		p = st;
		st = g[st].back();
		if(vis[st]) {
			cout << "NO\n";
			return;
		}
	}
	if(ans.size()!=26) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n" << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}