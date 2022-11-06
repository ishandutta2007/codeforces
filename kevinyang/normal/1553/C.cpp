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
		int ans = 9;
		for(int m = 0; m<(1<<10); m++){
			bool f = true;
			for(int i = 0; i<10; i++){
				if(s[i]=='1'&&(m&(1<<i)))continue;
				if(s[i]=='0'&&((m&(1<<i))==0))continue;
				if(s[i]=='?')continue;
				f = false;
			}
			if(!f)continue;
			int cnt1 = 0; int mx1 = 5; int cnt2 = 0; int mx2 = 5;
			for(int i = 0; i<10; i++){
				if(i%2==0){
					if(m&(1<<i))cnt1++;
					mx1--;
				}
				else{
					if(m&(1<<i))cnt2++;
					mx2--;
				}
				if(cnt1>cnt2+mx2)ans = min(ans,i);
				if(cnt2>cnt1+mx1)ans = min(ans,i);
			}
		}
		cout << ans+1 << "\n";
	}
	return 0;
}