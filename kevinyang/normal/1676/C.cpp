#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(string s, string t){
	int ans = 0;
	for(int i = 0; i<s.size(); i++){
		int v = s[i]-t[i];
		v = abs(v);
		ans+=v;
	}
	return (int)ans;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<string>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		int mn = (int)1e9;
		for(int i = 0; i<n; i++){
			for(int j = i+1; j<n; j++){
				mn = min(mn,f(arr[i],arr[j]));
			}
		}
		cout << mn << "\n";
	}
	return 0;
}