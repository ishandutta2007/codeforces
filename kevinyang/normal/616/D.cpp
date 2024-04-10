#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>freq(1e6+5);
	int cnt = 0;
	pair<int,int>ans = {1,2};
	int mx = 1;
	int cur = 0;
	for(int i = 1; i<=n; i++){
		while(cur<=n&&cnt<=k){
			cur++;
			if(cur==n+1)break;
			freq[arr[cur]]++;
			if(freq[arr[cur]]==1)cnt++;
		}
		if(cur-i>mx){
			ans = {i,cur};
			mx = cur-i;
		}
		freq[arr[i]]--;
		if(freq[arr[i]]==0)cnt--;
	}
	cout << ans.first << " " << ans.second-1 << "\n";
	return 0;
}