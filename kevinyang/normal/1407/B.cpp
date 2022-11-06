#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
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
		sort(arr.begin(),arr.end());
		vector<bool>vis(n);
		vector<int>ans;
		ans.push_back(arr[n-1]);vis[n-1] = true;
		int cur = arr[n-1];
		for(int i = 1; i<n; i++){
			int mx = 1;
			int ind = 0;
			for(int j = 0; j<n; j++){
				if(vis[j])continue;
				if(gcd(cur,arr[j])>=mx){
					mx = gcd(cur,arr[j]);
					ind = j;
				}
			}
			ans.push_back(arr[ind]);
			vis[ind] = true;
			cur = mx;
		}
		for(int nxt: ans){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}