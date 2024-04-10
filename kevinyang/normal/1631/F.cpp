#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		int v = 0;
		for(int i = 0; i<m; i++){
			int x;
			cin >> x;
			v = __gcd(x,v);
		}
		vector<int>freq(n+1);
		for(int i = 1; i<=n; i++){
			if(arr[i]<0){
				freq[i%v]++;
				freq[i%v]%=2;
			}
		}
		vector<int>mn(v,(int)1e9);
		int sum = 0;
		for(int i = 1; i<=n; i++){
			mn[i%v] = min(mn[i%v],abs(arr[i]));
		}
		int val = 0;
		for(int i = 0; i<v; i++){
			if(freq[i])val+=mn[i];
			sum+=mn[i];
		}
		int sub = min(sum-val,val);
		int ans = 0;
		for(int i = 1; i<=n; i++){
			ans+=abs(arr[i]);
		}
		ans-=sub*2;
		cout << ans << "\n";
	}
	return 0;
}