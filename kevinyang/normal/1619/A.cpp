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
		if(s.size()%2==0){
			int v = s.size()/2;
			if(s.substr(0,v)==s.substr(v,v))cout << "Yes\n";
			else cout << "No\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}