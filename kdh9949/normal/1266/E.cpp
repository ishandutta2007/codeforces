#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;

int n, q, a[N], c[N], tc;
ll tot;
map<pair<int, int>, int> mp;

void upd(int x, int y){
	tc -= min(a[x], c[x]);
	c[x] += y;
	tc += min(a[x], c[x]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		tot += a[i];
	}

	cin >> q;
	for(int i = 0; i < q; i++){
		int x, y, z;
		cin >> x >> y >> z;
		pair<int, int> pp = make_pair(x, y);
		if(mp.find(pp) != mp.end()) upd(mp[pp], -1);
		mp[pp] = z;
		upd(mp[pp], 1);
		cout << (tot - tc) << '\n';
	}

}