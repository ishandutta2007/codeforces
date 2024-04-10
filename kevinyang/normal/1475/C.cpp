#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,k;
		cin >> a >> b >> k;
		vector<pair<int,int>>arr(k+1);
		vector<int>freq(a+1);
		vector<int>freq2(b+1);
		for(int i = 1; i<=k; i++){
			int x;
			cin >> x;
			arr[i].first = x;
			freq[x]++;
		}
		for(int i = 1; i<=k; i++){
			int x;
			cin >> x;
			freq2[x]++;
			arr[i].second = x;
		}
		int ans = 0;
		for(int i = 1; i<=k; i++){
			int v = k-freq[arr[i].first]-freq2[arr[i].second]+1;
			ans+=v;
			//cout << ans << "\n";
		}
		cout << ans/2 << "\n";
	}
	return 0;
}