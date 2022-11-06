#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		vector<int>arr(n);
		set<int>s;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			s.insert(arr[i]);
		}
		sort(arr.begin(),arr.end());
		if(x>arr[n-1]){
			cout << (x+arr[n-1]-1)/arr[n-1] << "\n";
		}
		else{
			if(s.find(x)!=s.end())cout << "1\n";
			else cout << "2\n";
		}
	}
	return 0;
}