#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 101;
int n, m;
set<array<int, 2>> nxt[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	char c;
	for(int i = 0; i < n; i++) nxt[i].insert({-1, 1}), nxt[i].insert({m, 1});
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> c;
			if(c != '.') nxt[i].insert({j, c=='#'});//, cout << i << " " << j << endl;
		}
	ll ans = 0;
	int x = 0, y = 0, dir = 0, L = 0, R = 0;
	for(int iter = 5000400; iter--;) {
		//cout << x << " " << y << " " << dir << endl;
		if(x == n-1) {cout << ans <<'\n'; return 0;}
		if(nxt[x+1].lower_bound({y, 0})->at(0) != y) {
			x++;
			L = R = y;
			ans++;
			continue;
		}
		//for(auto i : nxt[x]) cout << i[0] << " "; cout << x << endl;
		auto it = nxt[x].lower_bound({y, 0});
		if(dir) it--;
		//cout << x << " - " << y << " " << it->at(0) << endl;
		if(abs(it->at(0)-y) > 1) {
			if(dir) L = max(L-1, it->at(0)+1), ans += abs(L-y), y = L;
			if(!dir) R = min(R+1, it->at(0)-1), ans += abs(R-y), y = R;
			continue;
		}
		if(it->at(1) == 0) nxt[x].erase(it);
		dir ^= 1;ans++;
	}
	cout << "Never\n";
}