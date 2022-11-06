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
		if(n<=2){
			cout << "0\n";
			continue;
		}
		int start = arr[n-1];
		int start2 = 0;
		for(int i = n-2; i>=0; i--){
			if(arr[i]>=start){
				start = arr[i];
			}
			else{
				start2 = i+1;
				break;
			}
		}
		int ans = 0;
		for(int i = start2-1; i>=0; i--){
			if(arr[start2]>=arr[i]){
				start2--;
			}
			else{
				ans = start2;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}