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

string N;

ll hoge(string S) {
	ll ret=1;
	FORR(c,S) if(c!='0') ret*=c-'0';
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll ma=0;
	cin>>N;
	ma=hoge(N);
	FOR(i,N.size()) if(N[i]>'0') {
		string M=N;
		M[i]--;
		for(j=i+1;j<N.size();j++) M[j]='9';
		ma=max(ma,hoge(M));
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}