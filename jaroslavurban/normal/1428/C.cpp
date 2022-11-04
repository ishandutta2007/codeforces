#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		string s;cin>>s;
		int n=s.size();
		int lft=0,res=0;
		for(int i=n-1;i>=0;--i)
			if(s[i]=='A'&&lft){--lft;++res;}
			else if(s[i]=='B')++lft;
		res+=lft/2;
		cout<<n-2*res<<endl;
	}
}