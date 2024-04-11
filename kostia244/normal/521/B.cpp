//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 9;
int n;
map<int, pi> pos;
map<pi, int> id;
vector<set<int>> p, ch;
bool canrem(int i) {
	int ok = 1;
	for(auto j : p[i]) {
		ok&=ch[j].size()>1;
	}
//	cout << i << " " << ok << ")\n";
	return ok;
}
void rem(int i) {
	for(auto j : p[i]) {
		ch[j].erase(i);
	}
	for(auto j : ch[i]) {
		p[j].erase(i);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	p.resize(n);
	ch.resize(n);
	for (int x, y, i = 0; i < n; i++) {
		cin >> y >> x;
		pos[i] = {x, y};
		id[ { x, y }] = i;
	}
	for(int i = 0; i < n; i++) {
		int x = pos[i].first, y = pos[i].second;
		for(int z = -1; z < 2; z++) {
			if(id.count({x+1, y+z}))
				p[i].insert(id[{x+1, y+z}]);
			if(id.count({x-1, y+z}))
				ch[i].insert(id[{x-1, y+z}]);
		}
	}
	set<int> can;
	for(int i = 0; i < n; i++) {
		int x = pos[i].first, y = pos[i].second;
		if(canrem(i)) can.insert(i);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
//		if(can.empty()) exit(0);
		int j = ((i&1)?*can.begin():*can.rbegin());
		ans = (ans*1ll*n + j)%mod;
		int x = pos[j].first, y = pos[j].second;
//		cout << j << "val:\n";
		rem(j);
		can.erase(j);
		id.erase(pos[j]);
		for(int z = -2; z < 3; z++){
			if(id.count({x, y+z})) {
				can.erase(id[{x, y+z}]);
			}
			if(id.count({x-1, y+z})) {
				can.erase(id[{x-1, y+z}]);
			}
		}
		for(int z = -2; z < 3; z++) {
			if(id.count({x, y+z})&&canrem(id[{x, y+z}])) {
				can.insert(id[{x, y+z}]);
			}
			x--;
			if(id.count({x, y+z})&&canrem(id[{x, y+z}])) {
				can.insert(id[{x, y+z}]);
			}
			x++;
		}
	}
	cout << ans;

}