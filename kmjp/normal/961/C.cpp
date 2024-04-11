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

int N;
string S[4][101];
string T[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,4) {
		FOR(j,N) cin>>S[i][j];
	}
	
	int mi=101010;
	vector<int> V={0,1,2,3};
	do {
		
		FOR(i,N) T[i]=S[V[0]][i]+S[V[1]][i];
		FOR(i,N) T[i+N]=S[V[2]][i]+S[V[3]][i];
		
		int tot=0;
		FOR(y,2*N) FOR(x,2*N) tot += ((x+y)%2)!=T[y][x]-'0';
		mi=min(mi,tot);
		
	} while(next_permutation(ALL(V)));
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}