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

int N,M;
int G[501][501];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		G[x-1][y-1]=G[y-1][x-1]=1;
	}
	
	int a=-1,c=-1;
	FOR(y,N) FOR(x,y) if(G[x][y]==0) a=x,c=y;
	if(a==-1) {
		cout<<"Yes"<<endl;
		cout<<string(N,'a')<<endl;
		return;
	}
	
	string S=string(N,'-');
	S[a]='a';
	S[c]='c';
	
	FOR(i,N) if(i!=a && i!=c) {
		if(G[i][a]==0 && G[i][c]==0) {
			cout<<"No"<<endl;
			return;
		}
		if(G[i][a]==1 && G[i][c]==0) S[i]='a';
		if(G[i][a]==0 && G[i][c]==1) S[i]='c';
		if(G[i][a]==1 && G[i][c]==1) S[i]='b';
	}
	
	FOR(y,N) FOR(x,y) if(G[x][y]^(abs(S[x]-S[y])<=1)) {
		cout<<"No"<<endl;
		return;
	}
	
	cout<<"Yes"<<endl;
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}