#include <bits/stdc++.h>
using namespace std;
#define int long long
int func(string s, char a, char b){
	int cnt = 0;
	bool f = false;
	bool f2 = false;
	for(int i = s.length()-1; i>=0; i--){
		if(f)break;
		if(f2&&s[i]==a){
			f = true; 
			break;
		}
		if(!f2&&s[i]==b){
			f2 = true;
			continue;
		}
		cnt++;
	}
	if(!f)return 100;
	return cnt;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int ans = 100;
		ans = min(ans,func(s,'0','0'));
		ans = min(ans,func(s,'2','5'));
		ans = min(ans,func(s,'5','0'));
		ans = min(ans,func(s,'7','5'));
		cout << ans << "\n";
	}
	return 0;
}