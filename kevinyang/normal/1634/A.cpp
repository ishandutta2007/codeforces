#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		string s2 = s;
		reverse(s2.begin(),s2.end());
		if(k==0||(s==s2)){
			cout << "1\n";
		}
		else{
			cout << "2\n";
		}
	}
	return 0;
}