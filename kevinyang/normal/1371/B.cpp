#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,r;
		cin >> n >> r;
		long long ans = 0;
		if(r<n){
			ans = (long long)r*(r+1)/2;
		}
		else{
			ans = (long long)(n)*(n-1)/2+1;
		}
		cout << ans << "\n";
	}
	return 0;
}