#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,p;
	cin >> n >> p;
	vector<string>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	vector<int>val(n+1);
	int cur = 0;
	for(int i = n-1; i>=0; i--){
		if(arr[i]=="halfplus"){
			cur*=2; cur++;
			val[i] = cur;
		}
		else{
			cur*=2;
			val[i] = cur;
		}
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		ans+=val[i]*p/2;
	}
	cout << ans << "\n";
	return 0;
}