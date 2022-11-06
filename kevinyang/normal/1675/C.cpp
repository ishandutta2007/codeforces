#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		s = " " + s;
		vector<int>a(n+1);
		vector<int>b(n+1);
		for(int i = 1; i<=n; i++){
			if(s[i]=='?'||s[i]=='1')a[i]++;
		}
		for(int i = 1; i<=n; i++){
			if(s[i]=='?'||s[i]=='0')b[i]++;
		}
		for(int i = 1; i<=n; i++){
			a[i]+=a[i-1];
			b[i]+=b[i-1];
		}
		int ans = 0;
		for(int i = 1; i<=n; i++){
			if(b[n]-b[i]==n-i&&a[i-1]==i-1){
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}