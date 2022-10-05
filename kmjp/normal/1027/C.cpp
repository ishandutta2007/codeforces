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

int T,N;
int A[1010110];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		map<int,int> M;
		scanf("%d",&N);
		FOR(i,N) scanf("%d",&x), M[x]++;
		
		vector<int> V;
		double ret=0;
		FORR(m,M) {
			if(m.second>=4) {
				x=y=m.first;
				goto out;
			}
			if(m.second>=2) V.push_back(m.first);
		}
		sort(ALL(V));
		x=y=0;
		FOR(i,V.size()-1) {
			double a=1.0*V[i]/V[i+1];
			if(a>ret) {
				ret=a;
				x=V[i];
				y=V[i+1];
			}
		}
		
		out:
		_P("%d %d %d %d\n",x,x,y,y);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}