#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = n;
	for(int i = 2; i*i<=n; i++){
		if(n%i==0){
			ans = gcd(ans,i);
			ans = gcd(ans,n/i);
		}
	}
	cout << ans << "\n";
	return 0;
}