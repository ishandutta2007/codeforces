#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n);
		int ans = 0;
		multiset<int>s;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			ans+=arr[i]/k;
			arr[i]%=k;
			s.insert(arr[i]);
		}
		while(s.size()){
			int x = *s.begin();
			s.erase(s.begin());
			if(s.size()){
				auto it = s.lower_bound(k-x);
				if(it==s.end())continue;
				ans++;
				s.erase(it);
			}
			else{
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}