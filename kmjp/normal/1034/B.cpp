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

ll H,W;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	if(H>W) swap(H,W);
	if(H==1) {
		ll ret=W/6*6;
		W%=6;
		if(W==4) ret+=2;
		if(W==5) ret+=4;
		cout<<ret<<endl;
	}
	else if(H==2) {
		if(W==2) {
			cout<<0<<endl;
		}
		else if(W==3 || W==7) {
			cout<<H*(W-1)<<endl;
		}
		else {
			cout<<H*W<<endl;
		}
	}
	else {
		cout<<H*W-(H*W%2)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}