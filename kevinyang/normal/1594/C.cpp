#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		char ch;
		cin >> n >> ch;
		string ss;
		cin >> ss;
		int cnt = n-1-count(ss.begin(),ss.end()-1,ch);
		int cnt2 = (ss[n-1]!=ch);
		if(count(ss.begin(),ss.end(),ch)==n){
			cout << "0\n";
			continue;
		}
		int ans = 0;
		for(int i = 2; i<=n; i++){
			int cnt = 0;
			for(int j = i; j<=n; j+=i){
				if(ss[j-1]!=ch)cnt++;
			}
			if(cnt==0)ans = i;
		}
		if(ans){
			cout << "1\n";
			cout << ans << "\n";
		}
		else{
			cout << "2\n";
			cout << n-1 << " " << n << "\n";
		}
	}
	return 0;
}