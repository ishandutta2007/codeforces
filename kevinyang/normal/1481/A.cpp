#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x,y;
		cin >> x >> y;
		string s;
		cin >> s;
		int u = 0, d = 0, r = 0, l = 0;
		for(int i = 0; i<s.length(); i++){
			if(s[i]=='U')u++;
			if(s[i]=='D')d++;
			if(s[i]=='R')r++;
			if(s[i]=='L')l++;
		}
		bool f = true;
		if(x>=0){
			if(r<x)f = false;
		}
		else{
			if(l<abs(x))f = false;
		}
		if(y>=0){
			if(u<y)f = false;
		}
		else{
			if(d<abs(y))f = false;
		}
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}