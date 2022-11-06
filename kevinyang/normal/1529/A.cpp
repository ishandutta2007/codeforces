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
	    sort(arr.begin(),arr.end());
	    int sum = 0;
	    for(int i = 0; i<n; i++){
	        sum+=arr[i];
	    }
	    int cnt = 0;
	    for(int i = n-1; i>=0; i--){
	        sum-=arr[i];
	        if(sum<arr[i]*i)cnt++;
	        else break;
	    }
	    cout << cnt << "\n";
	}
	return 0;
}