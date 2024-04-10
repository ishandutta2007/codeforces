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
		vector<int>a(n+1);
		vector<int>b(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		for(int i = 2; i<=n; i++){
			if(arr[i]>=arr[i-1]){
				a[i] = 1;
				a[i]+=a[i-1];
			}
			if(arr[i]<=arr[i-1]){
				b[i] = 1;
				b[i]+=b[i-1];
			}
		}
		bool f = false;
		if(a[n]==n-1||b[n]==n-1)f = true;
		for(int i = 2; i<=n; i++){
			if(a[n]-a[i]+b[i]==n-1)f = true;
		}
		if(f)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}