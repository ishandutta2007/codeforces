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
		int a = 0;
		int b = 0;
		int cnt = 1;
		for(int i = 1; i<s.length(); i++){
			if(s[i]!=s[i-1]){
				if(s[i]=='1')a+=cnt-1;
				else b+=cnt-1;
				cnt = 1;
			}
			else{
				cnt++;
			}
		}
		if(s[s.length()-1]=='0')a+=cnt-1;
		else b+=cnt-1;
		cout << max(a,b) << "\n";
	}
	return 0;
}