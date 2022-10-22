#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
		a[i] += x;
	}
	vector<int> b(m);
	for(int i = 0;i < m;i++){
		cin >> b[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(k >= n || k >= m){
		cout << -1;
		return 0;
	}
	int ans = 0;
	for(int i = 0;i <= k;i++){
		int m = a[i];
		auto it = lower_bound(b.begin(),b.end(),m);
		if(it == b.end()){
			cout << -1;
			return 0;
		}
		int z = it - b.begin();
		int p = k - i;
		z += p;
		if(z >= b.size()){
			cout << -1;
			return 0;
		}
		ans = max(ans,b[z] + y);
	}
	cout << ans;
	
}