#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize ("O3")
signed main() {
	int n,m,k;
	cin >> n >> m  >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	n = k;
	vector<pair<int,int> > a1(m);
	for(int i=0;i<m;i++){
		cin >> a1[i].first >> a1[i].second;
	}
	vector<int> sum(n + 1,0);
	vector<int> ans(n + 1,0);
	for(int i=1;i<=n;i++){
		sum[i] = sum[i - 1] + a[i - 1];
		ans[i] = ans[i - 1] + a[i - 1];
	}
	for(int i = 1;i <= n;i++){
		for(int x = 0; x < m;x++){
			if (i >= a1[x].first){
				ans[i] = min(ans[i], ans[i - a1[x].first]  + sum[i] - sum[i - a1[x].first + a1[x].second] );
			}
		}
	}
	cout << ans[k];
	
	
}