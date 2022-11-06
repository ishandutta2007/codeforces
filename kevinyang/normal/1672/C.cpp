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
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		int l = 0; int r = 0;
		for(int i = 2; i<=n; i++){
			if(arr[i]==arr[i-1]){
				l = i;
				break;
			}
		}
		for(int i = n-1; i>=1; i--){
			if(arr[i]==arr[i+1]){
				r = i;
				break;
			}
		}
		if(l==0||r<l)cout << "0\n";
		else cout << max(1LL,r-l) << "\n";
	}
	return 0;
}