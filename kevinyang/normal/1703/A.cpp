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
		for(int i = 0; i<3; i++){
			if(s[i]>='a'){
				s[i]-=('a'-'A');
			}
		}
		if(s=="YES")cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}