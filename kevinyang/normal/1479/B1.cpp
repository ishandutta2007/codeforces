#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>freq(n+1);
	int ans = 0; int both = 0; int cnt = 0;
	for(int i = 1; i<=n; i++){
		if(arr[i]!=arr[i-1]){
			ans++;
			if(both&&arr[i]!=both)cnt--;
			if(both&&arr[i]==both)cnt++;
			if(cnt==0)both = 0;
		}
		else{
			if(both!=arr[i]){
				both = 0; cnt = 0;
			}
			if(cnt!=2){
				both = arr[i];
				if(cnt==0)ans++;
				cnt = 2;
			}
		}
		//cout << both << " " <<  ans << "\n";
	}
	cout << ans << "\n";
	return 0;
}