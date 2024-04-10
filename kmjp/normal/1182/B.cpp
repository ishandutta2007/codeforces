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

int H,W;
string S[505];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int C=0;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='*') C++;
	}
	
	for(y=1;y<H-1;y++) for(x=1;x<W-1;x++) if(S[y][x]=='*' && S[y-1][x]=='*' && S[y][x-1]=='*' && S[y+1][x]=='*' && S[y][x+1]=='*') {
		
		int c=1;
		int cx,cy;
		for(cx=x-1;cx>=0;cx--) if(S[y][cx]=='.') break;
		c+=x-cx-1;
		for(cx=x+1;cx<W;cx++) if(S[y][cx]=='.') break;
		c+=cx-x-1;
		for(cy=y-1;cy>=0;cy--) if(S[cy][x]=='.') break;
		c+=y-cy-1;
		for(cy=y+1;cy<H;cy++) if(S[cy][x]=='.') break;
		c+=cy-y-1;
		if(c==C) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		return;
	}
	
	cout<<"NO"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}