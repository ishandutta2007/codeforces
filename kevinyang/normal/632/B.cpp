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
	string s;
	cin >> s;
	vector<int>psa(n+1);
	int ans = 0;
	int mn = 0;
	int cursum = 0;
	for(int i = 1; i<=n; i++){
		if(s[i-1]=='B')cursum+=arr[i];
	}
	ans = cursum;
	for(int i = 1; i<=n; i++){
		int v = 0;
		if(s[i-1]=='A')v+=arr[i];
		else v-=arr[i];
		psa[i] = psa[i-1]+v;
		ans = max(ans,cursum+psa[i]);
	}
	vector<int>suf(n+5);
	for(int i = n; i>=1; i--){
		int v = 0;
		if(s[i-1]=='A')v+=arr[i];
		else v-=arr[i];
		suf[i] = suf[i+1]+v;
		ans = max(ans,cursum+suf[i]);
	}
	cout << ans << "\n";
	return 0;
}