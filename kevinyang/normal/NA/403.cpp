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
		if(s[0]==')'||s.length()%2==1||s[s.length()-1]=='('){
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
		}
	}
	return 0;
}