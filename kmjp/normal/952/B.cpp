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

map<string,int> S[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int g=0;
	
	S[0]["no"]=5;
	S[0]["don't think so"]=1;
	S[0]["don't touch me"]=1;
	S[0]["not bad"]=1;
	S[0]["cool"]=1;
	S[0]["great"]=1;
	
	S[1]["no"]=3;
	S[1]["don't even"]=1;
	S[1]["are you serious?"]=1;
	S[1]["worse"]=1;
	S[1]["terrible"]=1;
	S[1]["no way"]=2;
	S[1]["go die in a hole"]=1;
	
	
	FOR(i,10) {
		cout<<i<<endl;
		getline(cin,s);
		
		if(S[0][s]==0) {
			cout<<"grumpy"<<endl;
			return;
		}
		if(S[1][s]==0) {
			cout<<"normal"<<endl;
			return;
		}
		S[0][s]--;
		S[1][s]--;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}