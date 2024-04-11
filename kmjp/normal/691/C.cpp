#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;

void print(string a,string b,int x) {
	cout<<a;
	if(b.size()) cout<<"."<<b;
	if(x) cout<<"E"<<x;
	cout<<endl;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	y=0;
	while(S[y]=='0') y++;
	S=S.substr(y);
	
	if(S=="") return _P("0\n");
	
	x = S.find('.');
	if(x == string::npos) {
		if(S.size()==1) {
			cout<<S<<endl;
		}
		else {
			x=S.size()-1;
			y=S.size();
			while(S[y-1]=='0') y--;
			S=S.substr(0,y);
			print(S.substr(0,1),S.substr(1),x);
		}
		
	}
	else {
		y=S.size();
		while(S[y-1]=='0') y--;
		S=S.substr(0,y);
		
		if(S==".") return _P("0\n");
		
		x = S.find('.');
		
		if(x==0) {
			S=S.substr(1);
			FOR(x,S.size()) if(S[x]!='0') break;
			S=S.substr(x);
			print(S.substr(0,1),S.substr(1),-x-1);
		}
		else {
			S.erase(S.begin()+x);
			y=S.size();
			while(S[y-1]=='0') y--;
			S=S.substr(0,y);
			print(S.substr(0,1),S.substr(1),x-1);
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}