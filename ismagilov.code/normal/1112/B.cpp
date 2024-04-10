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
	int n, k;
	cin >> n >> k;
	vc<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	vc<int> emptys;
	for (int i = 0; i < k; i++){
		emptys.pb(i);
	}
	vc<vc<int>> stops(150001);
	int nowm = 0;
	vc<int> lastwhere(k, 1000000000);
	vc<int> lastwheres(k, 0);
	vc<bool> canbegood(n);
	reverse(all(a));
	for (int i = 0; i < 150001; i++){
		if (nowm == n){
			break;
		}
		while(len(stops[i]) > 0){
			nowm++;
			emptys.pb(stops[i].back());
			lastwhere[emptys.back()] = 1000000000;
			stops[i].pop_back();
		}
		int x = (((100 * nowm / (double)n) + 0.5));
		while(len(a) > 0 && len(emptys) > 0){
			stops[i + a.back()].pb(emptys.back());
			lastwhere[emptys.back()] = i;
			a.pop_back();
			lastwheres[emptys.back()] = len(a);
			emptys.pop_back();
		}
		for (int j = 0; j < k; j++){
			if ((i - lastwhere[j] + 1) == x){
				canbegood[lastwheres[j]] = 1;
			}
		}
	}
	int ans = 0;
	for (auto v : canbegood){
		ans += v;
	}
	cout << ans;
}