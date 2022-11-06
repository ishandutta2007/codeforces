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
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			arr[i]%=2;
		}
		int zero = count(arr.begin(),arr.end(),0);
		int one = count(arr.begin(),arr.end(),1);
		if(abs(zero-one)>1){
			cout << "-1\n";
			continue;
		}
		vector<int>zeroes;
		vector<int>ones;
		for(int i = 0; i<n; i++){
			if(arr[i]==0)zeroes.push_back(i);
			else ones.push_back(i);
		}
		if(zero+1==one){
			int ans = 0;
			for(int i = 0; i<n; i+=2){
				ans+=abs(ones[i/2]-i);
			}
			cout << ans << "\n";
		}
		else if(one+1==zero){
			int ans = 0;
			for(int i = 0; i<n; i+=2){
				ans+=abs(zeroes[i/2]-i);
			}
			cout << ans << "\n";
		}
		else{
			assert(zero==one);
			int ans = (int)1e18;
			int cur = 0;
			for(int i = 0; i<n; i+=2){
				cur+=abs(ones[i/2]-i);
			}
			ans = cur;
			for(int i = n-1; i>=0; i-=2){
				cur-=abs(ones[i/2]-(i-1));
				cur+=abs(ones[i/2]-i);
			}
			ans = min(ans,cur);
			cout << ans << "\n";
		}
	}
	return 0;
}