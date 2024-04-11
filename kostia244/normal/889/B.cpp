#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
vvi g, gt;
string ans;
void dfs(int v) {
	if(count(all(ans), char('a'+v))) {
		cout << "NO";
		exit(0);
	}
	ans += char('a'+v);
	if(g[v].size())
		dfs(g[v][0]);
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	set<pair<int, int>> edges;
	int n;
	cin >> n;
	string s;
	vi use(26, 0);
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 1; j < s.size(); j++) {
			edges.insert( { s[j - 1] - 'a', s[j] - 'a' });
		}
		vi cnt(26, 0);
		for (int j = 0; j < s.size(); j++) {
			if (++cnt[s[j] - 'a'] > 1) {
				return cout << "NO", 0;
			}
			use[s[j] - 'a']=1;
		}
	}
	g.resize(26);
	gt.resize(26);
	for (auto u : edges) {
		g[u.first].pb(u.second);
		gt[u.second].pb(u.first);
	}
	vi st;
	for(int i = 0; i < 26; i++) {
		if(g[i].size()>1)
			return cout << "NO", 0;
		if(gt[i].size()>1)
			return cout << "NO", 0;
		if(use[i]&&!gt[i].size())
			st.pb(i);
	}
	sort(all(st));
	for(auto i : st)
		dfs(i);
	for(int i = 0; i < 26; i++)
		if(use[i]&&count(all(ans), char('a'+i))!=1)
			return cout << "NO", 0;
	cout << ans;
}