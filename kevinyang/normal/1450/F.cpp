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
		vector<int>arr(n+1);
		vector<int>freq(n+1);
		int mx = 0;
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			freq[arr[i]]++;
			mx = max(mx,freq[arr[i]]);
		}
		if((n+1)/2<mx){
			cout << "-1\n";
			continue;
		}
		for(int i = 1; i<=n; i++){
			freq[i] = 0;
		}
		freq[arr[1]]++;
		freq[arr[n]]++;
		int cnt = 0;
		for(int i = 2; i<=n; i++){
			if(arr[i]==arr[i-1]){
				freq[arr[i]]++;
				cnt++;
				freq[arr[i-1]]++;
			}
		}
		mx = 0;
		for(int i = 1; i<=n; i++){
			mx = max(mx,freq[i]);
		}
		cout << max(cnt,mx-1-1) << "\n";
	}
	return 0;
}