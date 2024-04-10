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
		int zeroes = 0;
		int ones = 0;
		for(int i = 0; i<s.length(); i++){
			if(s[i]=='0')zeroes++;
			else ones++;
		}
		if(min(zeroes,ones)%2==1)cout << "DA\n";
		else cout << "NET\n";
	}
	return 0;
}