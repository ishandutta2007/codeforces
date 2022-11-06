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
		vector<int>freq(n+1);
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			int x;
			cin >> x;
			arr[i] = x;
			freq[x]++;
		}
		int ans = -1;
		for(int i = 1; i<=n; i++){
			if(freq[i]==1){
				for(int j = 1; j<=n; j++){
					if(arr[j]==i){
						ans = j;
						break;
					}
				}
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}