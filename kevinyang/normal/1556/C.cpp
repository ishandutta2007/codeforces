#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	for(int i = 0; i<n; i+=2){
		bool f = true;
		int cur = 0;
		int maxrem = (int)1e18;
		for(int j = i+1; j<n; j+=2){
			cur+=arr[j-1];
			cur-=arr[j];
			if(!f)continue;
			if(cur>maxrem)continue;
			if(cur<0){
				f = false;
				int temp = arr[j];
				arr[j]+=cur;
				int left = arr[i]-cur;
				int right = arr[j];
				cur = 0;
				if(left<=0)continue;
				ans+=min({maxrem-cur,right-1,left-1})+1;
				//cout << i << " " << j << " " << min({maxrem-cur,right-1,left-1})+1 << "\n";
				maxrem = min(maxrem,cur);
				arr[j] = temp;
				f = false;
				continue;
			}
			
			//cur <=maxrem
			int left = arr[i]-cur;
			int right = arr[j];
			if(left<=0)continue;
			ans+=min({maxrem-cur,right-1,left-1})+1;
			//cout << i << " " << j << " " << min({maxrem-cur,right-1,left-1})+1 << "\n";
			maxrem = min(maxrem,cur);
			
		}
	}
	cout << ans << "\n";
	return 0;
}