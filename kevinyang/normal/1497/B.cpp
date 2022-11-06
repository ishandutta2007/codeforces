#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int>freq(m);
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			freq[x%m]++;
		}
		int ans = 0;
		if(freq[0]>0)ans++;
		if(m%2==0&&freq[m/2]>0)ans++;
		for(int i = 1; i<(m+1)/2; i++){
			if(freq[i]==0&&freq[m-i]==0)continue;
			if(abs(freq[i]-freq[m-i])<=1)ans++;
			else ans+=abs(freq[i]-freq[m-i]);
		}
		cout << ans << "\n";
	}
	return 0;
}