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
int ID[101][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,4*N) {
		if(i<2*N) {
			ID[i/2][3*(i%2)]=i+1;
		}
		else {
			ID[(i-2*N)/2][1+(i%2)]=i+1;
		}
	}
	vector<int> V;
	FOR(i,N) {
		FOR(j,4) {
			int D[4]={1,0,2,3};
			if(ID[i][D[j]]<=M) V.push_back(ID[i][D[j]]);
		}
	}
	FORR(r,V) _P("%d ",r);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}