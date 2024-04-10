#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int v = 0;
		int n;
		cin >> n;
		int sum = 0;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			sum+=arr[i];
		}
		int cur = 0; 
		for(int i = 0; i<n-1; i++){
			cur+=arr[i];
			if(cur<0)cur = 0;
			v = max(v,cur);
		}
		cur = 0;
		for(int i = 1; i<n; i++){
			cur+=arr[i];
			if(cur<0)cur = 0;
			v = max(v,cur);
		}
		if(sum>v){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}