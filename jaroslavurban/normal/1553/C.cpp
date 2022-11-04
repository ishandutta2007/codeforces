#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n=10;

void ProGamerMove(){
	string s;cin>>s;
	int sc[2]={},lft[2]={5,5};
	int res=n;
	for(int i=0;i<n;++i){
		if(i&1){
			if(s[i]=='1')++sc[i&1];
		}else{
			if(s[i]=='?'||s[i]=='1')++sc[i&1];
		}
		--lft[i&1];
		if(sc[0]+lft[0]<sc[1]||sc[1]+lft[1]<sc[0]){res=min(res,i+1);break;}
	}
	sc[0]=sc[1]=0;lft[0]=lft[1]=5;
	for(int i=0;i<n;++i){
		if(i&1){
			if(s[i]=='?'||s[i]=='1')++sc[i&1];
		}else{
			if(s[i]=='1')++sc[i&1];
		}
		--lft[i&1];
		if(sc[0]+lft[0]<sc[1]||sc[1]+lft[1]<sc[0]){res=min(res,i+1);break;}
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}