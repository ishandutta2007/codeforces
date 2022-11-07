#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	vector<int>arr2(n+1);
	int ans = 0; int sum = 0;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=n; i++){
		cin >> arr2[i];
		sum+=arr2[i]*arr[i];
	}
	for(int i = 1; i<=n; i++){
		int l = i; int r = i;
		int cur = sum;
		while(l>=1&&r<=n){
			cur-=arr[l]*arr2[l]+arr[r]*arr2[r];
			cur+=arr[l]*arr2[r]+arr[r]*arr2[l];
			l--; r++;
			ans = max(ans,cur);
		}
	}
	for(int i = 1; i<n; i++){
		int l = i; int r = i+1;
		int cur = sum;
		while(l>=1&&r<=n){
			cur-=arr[l]*arr2[l]+arr[r]*arr2[r];
			cur+=arr[l]*arr2[r]+arr[r]*arr2[l];
			l--; r++;
			ans = max(ans,cur);
		}
	}
	cout << ans << "\n";
	return 0;
}