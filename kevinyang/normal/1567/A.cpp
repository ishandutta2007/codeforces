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
		for(char nxt: s){
			if(nxt=='L')cout << "L";
			if(nxt=='R')cout << "R";
			if(nxt=='U')cout << "D";
			if(nxt=='D')cout << "U";
		}
		cout << "\n";
	}
	return 0;
}