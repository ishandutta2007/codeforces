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
		string s;
		cin >> s;
		s = " " + s;
		int ans = 0;
		for(int i = 1; i<=n; i++){
			int cur = 0;
			int cnt = 0;
			int amt = 0;
			for(int j = i; j<=n; j++){
				if(s[j]=='-')cur++;
				else cur = 0;
				if(cur==2){
					cur = 0;
					cnt++;
				}
				if(s[j]=='-')amt--;
				if(s[j]=='+')amt++;
				if(amt%3==0&&amt<=0&&(amt/3)*-1<=cnt){
					ans++;
				}
				//cout << i << " " << amt << "\n";
			}
			//cout << ans << " ";
		}
		cout << ans << "\n";
	}
	return 0;
}