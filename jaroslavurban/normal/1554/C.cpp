#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,m,big=0,res=0;cin>>n>>m;++m;
	for(int i=31;i>=0;--i){
		bool ns=1<<i&n,ms=1<<i&m;
		if(ns==ms)continue;
		if(ns==1)big=true;
		else res|=!big<<i;
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}