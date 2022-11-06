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
		map<char,int>hm;
		for(int i = 0; i<6; i++){
			hm[s[i]] = i;
		}
		if(hm['r']<hm['R']&&hm['g']<hm['G']&&hm['b']<hm['B']){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}