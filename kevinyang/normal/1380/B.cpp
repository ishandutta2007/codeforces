#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		int r = 0;
		int s = 0;
		int p = 0;
		for(int i = 0; i<str.length(); i++){
			if(str[i]=='R')r++;
			if(str[i]=='S')s++;
			if(str[i]=='P')p++;
		}
		if(r>=s && r>=p){
			for(int i = 0; i<str.length(); i++){
				cout << "P";
			}
		}
		else if(s>=r && s>=p){
			for(int i = 0; i<str.length(); i++){
				cout << "R";
			}
		}
		else{
			for(int i = 0; i<str.length(); i++){
				cout << "S";
			}
		}
		cout << "\n";
	}
	return 0;
}