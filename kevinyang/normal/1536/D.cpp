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
		set<int>s;
		bool f = true;
		s.insert(arr[0]);
		for(int i = 1; i<n; i++){
			s.insert(arr[i]);
			if(arr[i]==arr[i-1])continue;
			if(arr[i]>arr[i-1]){
				if(*--s.lower_bound(arr[i])==arr[i-1])continue;
				f = false;
			}
			if(arr[i]<arr[i-1]){
				if(*--s.lower_bound(arr[i-1])==arr[i])continue;
				f = false;
			}
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}