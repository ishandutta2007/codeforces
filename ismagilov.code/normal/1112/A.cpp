#include <bits/stdc++.h>

#define int long long
#define ld long double
#define fs first
#define sc second
#define vc vector
#define pr pair
#define mp make_pair
#define pb push_back
#define len(v) (int)v.size()
#define all(v) v.begin(), v.end()

#pragma GCC optimize("Ofast")

using namespace std;

const int INF = 2e9;

signed main(){
	#ifdef __linux__
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vc<int> p(n);
	vc<int> s(n);
	vc<int> c(k);
	vc<bool> used(n + 1);
	for (auto &v : p){
		cin >> v;
	}
	for (auto &v : s){
		cin >> v;
	}
	for (auto &v : c){
		cin >> v;
		used[v - 1] = 1;
	}
	vc<pr<int, int>> x[m + 1];
	for (int i = 0; i < n; i++){
		x[s[i]].pb({p[i], i});
	}
	int ans = k;
	for (int i = 0; i <= m; i++){
		sort(all(x[i]));
		if (len(x[i]) > 0 && used[x[i].back().sc]){
			ans--;
		}
	}
	cout << ans;
}