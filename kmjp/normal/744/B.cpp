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
int M[1010];
int R[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) M[i]=1<<30;
	
	for(i=0;i<=9;i++) {
		vector<int> V[2];
		FOR(j,N) {
			if(j&(1<<i)) V[1].push_back(j+1);
			else V[0].push_back(j+1);
		}
		FOR(j,2) if(V[j].size()) {
			_P("%d\n",V[j].size());
			FOR(x,V[j].size()) _P("%d%c",V[j][x],(x==V[j].size()-1)?'\n':' ');
			fflush(stdout);
			FOR(x,N) scanf("%d",&R[x]);
			FOR(x,N) {
				if((x&(1<<i)) && j==0) M[x]=min(M[x],R[x]);
				if((x&(1<<i))==0 && j) M[x]=min(M[x],R[x]);
			}
		}
	}
	_P("-1\n");
	FOR(x,N) _P("%d%c",M[x],(x==N-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}