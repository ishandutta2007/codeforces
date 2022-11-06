#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<int>nums;
	string cur = "1";
	for(int i = 0; i<11; i++){
		nums.push_back(stoll(cur));
		cur+="1";
	}
	vector<int>nums2;
	for(int nxt: nums){
		for(int i = 1; i<10; i++){
			nums2.push_back(nxt*i);
		}
	}
	sort(nums2.begin(),nums2.end());
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = upper_bound(nums2.begin(),nums2.end(),n)-nums2.begin();
		cout << ans << "\n";
	}
	return 0;
}