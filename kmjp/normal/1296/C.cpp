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
int N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		map<pair<int,int>,int> M;
		M[{0,0}]=0;
		int mi=1<<30;
		int A=0,B=0;
		x=y=0;
		FOR(i,N) {
			if(S[i]=='L') x--;
			if(S[i]=='R') x++;
			if(S[i]=='U') y++;
			if(S[i]=='D') y--;
			
			if(M.count({x,y})) {
				if(i+1-M[{x,y}]<mi) {
					mi=i+1-M[{x,y}];
					A=M[{x,y}]+1;
					B=i+1;
				}
			}
			M[{x,y}]=i+1;
		}
		
		if(mi==1<<30) {
			cout<<-1<<endl;
		}
		else {
			cout<<A<<" "<<B<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}