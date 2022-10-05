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

int T;
int W,N;
string S[3];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>T;
	while(T--) {
		cin>>W>>N;
		FOR(i,3) cin>>S[i], S[i]+="................";
		W+=15;
		for(x=0;x+3<W;x+=3) {
			FOR(y,3) if(S[y][x]=='s') {
				if(S[y][x+1]!='.' && S[y][x+1]!='s' ) continue;
				for(z=max(0,y-1);z<=min(2,y+1);z++) if(S[z][x+1]=='.') S[z][x+1]='s';
			}
			FOR(y,3) if(S[y][x+1]=='s' && S[y][x+2]=='.') S[y][x+2]='s';
			FOR(y,3) if(S[y][x+2]=='s' && S[y][x+3]=='.') S[y][x+3]='s';
		}
		if(S[0][W-5]=='s' || S[1][W-5]=='s' || S[2][W-5]=='s') cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}