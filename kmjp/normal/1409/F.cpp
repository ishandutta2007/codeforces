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

int N,K;
string S,T;

int from[202][202];
int to[202][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S>>T;
	
	if(T[0]==T[1]) {
		x=0;
		FORR(c,S) if(c==T[0]) x++;
		x=min(N,x+K);
		cout<<x*(x-1)/2<<endl;
		return;
	}
	
	FOR(x,202) FOR(y,202) from[x][y]=-1<<30;
	from[0][K]=0;
	FOR(i,N) {
		FOR(x,202) FOR(y,202) to[x][y]=-1<<30;
		FOR(x,i+1) FOR(y,K+1) {
			to[x][y]=max(to[x][y],from[x][y]);
			if(S[i]==T[0]) to[x+1][y]=max(to[x+1][y],from[x][y]);
			if(y) to[x+1][y-1]=max(to[x+1][y-1],from[x][y]);
			if(S[i]==T[1]) to[x][y]=max(to[x][y],from[x][y]+x);
			if(y) to[x][y-1]=max(to[x][y-1],from[x][y]+x);
			
		}
		swap(from,to);
	}
	
	int ma=0;
	FOR(x,202) FOR(y,202) ma=max(ma,from[x][y]);
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}