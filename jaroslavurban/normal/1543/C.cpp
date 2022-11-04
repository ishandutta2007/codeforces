#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld ex=0,v,EPS=1e-10;

void dfs(int dep,ld prob,ld a,ld b,ld c){
//	cerr<<dep<<setprecision(4)<<fixed<<" "<<prob<<" "<<c<<" "<<prob*c<<endl;
//	cerr<<dep<<setprecision(4)<<fixed<<" "<<prob<<" "<<a<<" "<<b<<" "<<c<<endl;
	ex+=prob*c*dep;
	if(c+EPS>=1||prob<EPS)return;
	// choose a
	if(a-EPS>=0){
		ld diff=min(a,v);
		ld na=a-diff;
		ld nb,nc;
		if(b-EPS>=0){
			nb=b+diff/2;
			nc=c+diff/2;
		}else{
			nb=b;
			nc=c+diff;
		}
		dfs(dep+1,prob*a,na,nb,nc);
	}
	// choose b
	if(b-EPS>=0){
		ld diff=min(b,v);
		ld nb=b-diff;
		ld na,nc;
		if(a-EPS>=0){
			na=a+diff/2;
			nc=c+diff/2;
		}else{
			na=a;
			nc=c+diff;
		}
		dfs(dep+1,prob*b,na,nb,nc);
	}
}

void ProGamerMove(){
	ex=0;
	ld a,b,c;cin>>a>>b>>c>>v;
	dfs(1,1,a,b,c);
	cout<<setprecision(11)<<fixed<<ex<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}