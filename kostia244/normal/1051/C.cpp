#include<bits/stdc++.h>
#define pb push_back
using namespace std;using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
int n;
vector<int> g[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		g[t].pb(i);
	}
	string s(n, 'A');
	int l = 0, r = 0;
	for(int i = 0; i < 110; i++) {
		if(g[i].size() == 1) {
			if(l > r)
				s[g[i][0]] = 'B';
			(l == r ? l : r)++;
		}
	}
	for(int i = 0; i < 110; i++) {
		if(g[i].size() < 3) continue;
		if(l > r) s[g[i][0]] = 'B', r++;
	}
	if(l == r) cout << "YES\n" << s;
	else cout << "NO\n";
}