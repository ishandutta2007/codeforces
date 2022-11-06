#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
int modpow(int x, int y){
	return !y?1:((y%2==1?x:1)*modpow(x*x%mod,y/2)%mod);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int cnt = 0;
		for(int i = 0; i<n; i++){
			string s;
			cin >> s;
			cnt+=count(s.begin(),s.end(),'#');
		}
		if(cnt==n*m){
			cout << (modpow(2,cnt)+mod-1)%mod << "\n"; 
		}
		else{
			cout << modpow(2,cnt) << "\n";
		}
	}
	return 0;
}