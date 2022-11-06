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
		}
		int mx = 0;
		int sum = 0;
		for(int i = 0; i<n; i++){
			mx = max(mx,arr[i]);
			sum+=arr[i];
		}
		if(mx>sum-mx||sum%2==1){
			cout << "T\n";
		}
		else{
			cout << "HL\n";
		}
	}
	return 0;
}