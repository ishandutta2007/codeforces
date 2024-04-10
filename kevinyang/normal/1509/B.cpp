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
		bool f = true;
		if(count(s.begin(),s.end(),'T')!=count(s.begin(),s.end(),'M')*2)f = false;
		int cnt = 0;
		for(int i = 0; i<n; i++){
			if(s[i]=='T')cnt++;
			else cnt--;
			if(cnt<0)f = false;
		}
		cnt = 0;
		for(int i = n-1; i>=0; i--){
			if(s[i]=='T')cnt++;
			else cnt--;
			if(cnt<0)f = false;
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}