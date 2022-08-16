#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
const int N = 1000005;

int n, m;
int L[N];
vi dis[N], sum[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<n; i++) {
		scanf("%d", L+i);
	}
	for (int i=n; i; i--) {
		dis[i].push_back(0);
		if(2 * i + 1 <= n){
			int x = 0, y = 0;
			int ind1 = 2 * i, ind2 = 2 * i + 1;
			while(x < dis[ind1].size() || y < dis[ind2].size()){
				if(x == dis[ind1].size()) dis[i].push_back(dis[ind2][y++] + L[ind2 - 1]);
				else if(y == dis[ind2].size()) dis[i].push_back(dis[ind1][x++] + L[ind1 - 1]);
				else if(dis[ind1][x] + L[ind1 - 1] < dis[ind2][y] + L[ind2 - 1]){
					dis[i].push_back(dis[ind1][x++] + L[ind1 - 1]);
				}
				else dis[i].push_back(dis[ind2][y++] + L[ind2 - 1]);
			}
		}
		else if(2 * i <= n){
			for (auto d : dis[2*i])
				dis[i].push_back(L[2*i-1] + d);
		}
		// sort(dis[i].begin(), dis[i].end());
		sum[i].resize(dis[i].size()+1);
		for (int j=1; j <= dis[i].size(); j++)
			sum[i][j] = sum[i][j-1] + dis[i][j-1];
	}
	int a, h;
	while (m--) {
		scanf("%d%d", &a, &h);
		ll ans = 0, len = 0, p = 0;
		while (a && h>=0) {
			int id = upper_bound(dis[a].begin(), dis[a].end(), h) - dis[a].begin();
			// cout << id << ": " << sum[a][id] << endl;
			ans += ll(id) * h - sum[a][id];
			if (p) {
				// cout << id << ": " << sum[a][id] << endl;
				id = upper_bound(dis[p].begin(), dis[p].end(), h-len) - dis[p].begin();
				ans -= ll(id) * (h-len) - sum[p][id];
			}
			len = L[a-1];
			h -= len;
			p = a;
			a /= 2;
		}
		printf("%lld\n", ans);
	}

	return 0;
}