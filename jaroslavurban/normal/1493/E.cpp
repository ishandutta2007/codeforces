#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string add(string s){
	int c=1,i=s.size()-1;
	while(i>=0&&c){
		if(s[i]=='0'){
			s[i]='1';
			c=0;
		}else s[i]='0';
		--i;
	}
	if(c){
		s.insert(0,"1");
	}
	return s;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	string l,r;
	int n;cin>>n>>l>>r;
	if(l[0]!=r[0])cout<<string(n,'1')<<'\n';
	else{
		if(r[n-1]=='1'||add(l)==r)cout<<r<<'\n';
		else if(l!=r)cout<<add(r)<<'\n';
		else cout<<r<<'\n';
	}
}