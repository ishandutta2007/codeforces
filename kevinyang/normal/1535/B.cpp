#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			if(x%2==1)arr.push_back(x);
		}
		int ans = n*(n-1)/2;
		int sz = arr.size();
		for(int i = 0; i<sz; i++){
			for(int j = i+1; j<sz; j++){
				if(gcd(arr[i],arr[j])==1)ans--;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}