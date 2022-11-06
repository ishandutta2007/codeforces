#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,p;
	cin >> n >> p;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	vector<int>ans;
	for(int i = 0; i<=2000; i++){
		int product = 1;
		bool f = true;
		for(int j = 1; j<=n; j++){
			int nums = lower_bound(arr.begin(), arr.end(),i+j) - arr.begin();
			nums-=(j-1);
			product*=nums;
			product%=p;
			if(product==0){
				f = false;
				break;
			}
		}
		if(f){
			ans.push_back(i);
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}