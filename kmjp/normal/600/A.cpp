#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;
vector<string> A,B;

int isnum(string s) {
	if(s.empty()) return 0;
	if(s.size()==1) return isdigit(s[0]);
	if(s[0]=='0') return 0;
	FORR(r,s) if(isdigit(r)==0) return 0;
	return 1;
}

void output(vector<string> V) {
	if(V.size()==0) {
		cout<<"-"<<endl;
	}
	else {
		int i;
		cout<<"\"";
		FOR(i,V.size()) {
			if(i) cout<<",";
			cout<<V[i];
		}
		cout<<"\""<<endl;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	S+=";";
	s="";
	FORR(r,S) {
		if(r==','||r==';') {
			if(isnum(s)) A.push_back(s);
			else B.push_back(s);
			s="";
		}
		else s+=r;
	}
	
	output(A);
	output(B);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}