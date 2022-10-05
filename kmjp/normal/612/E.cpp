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
int A[1001000],C[1001000];
int used[1010101];
vector<int> R[1010100];
int rem[1010100];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) cin>>A[i], A[i]--;
	MINUS(C);
	MINUS(rem);
	
	FOR(i,N) if(C[i]==-1) {
		x=i;
		while(x!=i || R[i].empty()) {
			C[x]=-2;
			R[i].push_back(x);
			x=A[x];
		}
		r=R[i].size();
		if(r%2==1) {
			FOR(j,r) C[R[i][j]]=R[i][(j+r/2+1)%r];
		}
		else {
			if(rem[r]==-1) rem[r]=i;
			else {
				y=rem[r];
				FOR(j,r) {
					C[R[y][j]]=R[i][j];
					C[R[i][j]]=R[y][(j+1)%r];
				}
				rem[r]=-1;
			}
		}
	}
	
	FOR(i,N) if(C[i]<0) return _P("-1\n");
	FOR(i,N) _P("%d ",C[i]+1);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}