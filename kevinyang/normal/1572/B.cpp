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
		int xorsum = 0;
		for(int i = 1; i<=n; i++){
			xorsum^=arr[i];
		}
		if(xorsum==1){
			cout << "NO\n";
			continue;
		}
		vector<int>ans;
		if(n%2==1){
			for(int i = 1; i<=n-2; i+=2){
				ans.push_back(i);
			}
			for(int i = n-4; i>=1; i-=2){
				ans.push_back(i);
			}
		}
		else{
			xorsum = 0; int idx = 0;
			for(int i = 1; i<=n; i++){
				xorsum^=arr[i];
				if(i%2==1&&xorsum==0){
					idx = i; break;
				}
			}
			for(int i = 1; i<=idx-2; i+=2){
				ans.push_back(i);
			}
			for(int i = idx-4; i>=1; i-=2){
				ans.push_back(i);
			}
			for(int i = idx+1; i<=n-2; i+=2){
				ans.push_back(i);
			}
			for(int i = n-4; i>=idx+1; i-=2){
				ans.push_back(i);
			}
			if(idx==0){
				cout << "NO\n";
				continue;
			}
		}
		cout << "YES\n";
		cout << ans.size() << "\n";
		for(int nxt: ans){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}