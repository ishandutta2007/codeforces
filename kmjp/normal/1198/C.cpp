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
int N,M;
int did[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		N*=3;
		
		FOR(i,N) did[i]=0;
		
		vector<int> C;
		FOR(i,M) {
			int U,V;
			scanf("%d%d",&U,&V);
			U--;
			V--;
			
			if(did[U]==0 && did[V]==0) {
				C.push_back(i+1);
				did[U]=did[V]=1;
			}
		}
		
		if(C.size()>=N/3) {
			_P("Matching\n");
			FOR(i,N/3) _P("%d ",C[i]);
			_P("\n");
			continue;
		}
		C.clear();
		FOR(i,N) if(did[i]==0) C.push_back(i+1);
		_P("IndSet\n");
		FOR(i,N/3) _P("%d ",C[i]);
		_P("\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}