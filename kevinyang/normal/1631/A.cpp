#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>a(n+1);
		vector<int>b(n+1);
		for(int i = 1; i<=n; i++){
			cin >> a[i];
		}
		for(int i = 1; i<=n; i++){
			cin >> b[i];
		}
		int mx = 0; int mx2 = 0;
		for(int i = 1; i<=n; i++){
			if(a[i]<b[i])swap(a[i],b[i]);
			mx = max(mx,a[i]);
			mx2 = max(mx2,b[i]);
		}
		cout << mx*mx2 << "\n";
	}
	return 0;
}