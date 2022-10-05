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

int ok[256],ast;
string S,T;
string P1,P2;
int N;
string Q;

int match(string a,string b) {
	if(a.size()!=b.size()) return 0;
	int i;
	FOR(i,a.size()) {
		if(a[i]=='?') {
			if(ok[b[i]]==0) return 0;
		}
		else {
			if(a[i]!=b[i]) return 0;
		}
	}
	return 1;
}

int isbad(string s) {
	FORR(c,s) if(ok[c]==1) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	FORR(c,S) ok[c]=1;
	
	FOR(i,T.size()) if(T[i]=='*') {
		P1=T.substr(0,i);
		P2=T.substr(i+1);
		ast=1;
	}
	cin>>N;
	while(N--) {
		cin>>Q;
		
		if(ast==0) {
			if(match(T,Q)) {
				cout<<"YES"<<endl;
			}
			else {
				cout<<"NO"<<endl;
			}
		}
		else {
			if(Q.size()<P1.size()+P2.size()) {
				cout<<"NO"<<endl;
			}
			else if(match(P1,Q.substr(0,P1.size())) && match(P2,Q.substr(Q.size()-P2.size()))
			        && isbad(Q.substr(P1.size(),Q.size()-P1.size()-P2.size()))) {
				cout<<"YES"<<endl;
			}
			else {
				cout<<"NO"<<endl;
			}
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