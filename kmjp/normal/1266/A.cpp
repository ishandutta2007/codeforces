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


int T;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(i,T) {
		cin>>S;
		int C[10]={};
		int sum=0,even=0;
		FORR(c,S) {
			sum+=c-'0';
			if(c%2==0) even++;
			C[c-'0']++;
		}
		
		if(C[0]==S.size()) {
			cout<<"red"<<endl;
		}
		else if(C[0]>0 && even>1 && sum%3==0) {
			cout<<"red"<<endl;
		}
		else {
			cout<<"cyan"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}