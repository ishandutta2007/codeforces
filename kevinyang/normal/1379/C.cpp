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
		vector<int>arr(m);
		vector<int>arr2(m);
		for(int i = 0; i<m; i++){
			cin >> arr[i] >> arr2[i];
		}
		map<int,bool>hm;//arr[i]*2e9 + arr2[i] --> bool
		int ans = 0;
		vector<pair<int,int>>sorted(m);
		vector<pair<int,int>>sorted2(m);
		for(int i = 0; i<m; i++){
			sorted[i] = make_pair(arr[i],arr2[i]);
			sorted2[i] = make_pair(arr2[i],arr[i]);
		}
		sort(sorted.begin(), sorted.end());
		sort(sorted2.begin(), sorted2.end());
		int idx = m-1;
		int sum = 0;
		for(int i = m-1; i>=0; i--){
			int cur = sorted2[i].first;
			while(true){
				if(sorted[idx].first>=cur&&idx>=0&&n-(m-1-idx)>0){
					sum+=sorted[idx].first;
					hm[sorted[idx].first*2e9+sorted[idx].second] = true;
					idx--;
				}
				else{
					break;
				}
			}
			if(hm[sorted2[i].second*2e9+sorted2[i].first]==true&&idx!=m-1){
				ans = max(ans,sum+sorted2[i].first*(n-(m-1-idx)));
			}
			else{
				if(n-(m-1-idx)>=1)
				ans = max(ans,sum+sorted2[i].first*(n-(m-1-idx)-1)+sorted2[i].second);
			}
			ans = max(ans,sum);
			//cout << ans << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}