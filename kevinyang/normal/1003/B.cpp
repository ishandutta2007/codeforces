#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int a,b,x;
	cin >> a >> b >> x;
	string s = "";
	if(a<b){
		s = "1";
		b--;
		for(int i = 0; i<x; i++){
			s+=(char)(i%2+'0');
			if(i%2==0)a--;
			else b--;
		}
		for(int i = 0; i<b; i++){
			cout << "1";
		}
		cout << s[0];
		for(int i = 0; i<a; i++){
			cout << "0";
		}
		for(int i = 1; i<s.length(); i++){
			cout << s[i];
		}
	}
	else{
		s = "0";
		a--;
		for(int i = 0; i<x; i++){
			s+=(char)((i+1)%2+'0');
			if(i%2==0)b--;
			else a--;
		}
		for(int i = 0; i<a; i++){
			cout << "0";
		}
		cout << s[0];
		for(int i = 0; i<b; i++){
			cout << "1";
		}
		for(int i = 1; i<s.length(); i++){
			cout << s[i];
		}
	}
	return 0;
}