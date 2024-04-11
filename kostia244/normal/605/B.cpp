#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vector<pair<pi, int>> a;
pi e[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	a.resize(m);
	int z = 0;
	for(auto &i : a) cin >> i.first.first >> i.first.second, i.second = z++, i.first.second*=-1;
	sort(all(a));
	for(int j = 1, k = -1, v = 2, i = 0; i < m; i++) {
//		cout << a[i].first.first << "\n";
		if(a[i].first.second) {
			e[a[i].second] = pi{v-1, v};
			v++;
//			cout << v-1 << " " << v << " " << a[i].first << "\n";
		} else {
			while(k<=0) {
				j++;
				k = j-2;
			}
//			cout << j << " " << k <<
			if(j>=v) return cout << -1, 0;
			e[a[i].second] = pi{k--, j};
		}
	}
	for(int i = 0; i < m; i++)
		cout << e[i].first << " " << e[i].second << "\n";
}