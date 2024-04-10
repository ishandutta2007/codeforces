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

int H,W;
int A[1010][1010];
ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(A);
	cin>>H>>W;
	FOR(y,H) {
		cin>>i;
		FOR(x,i) A[y][x]=0;
		A[y][i]=1;
	}
	FOR(x,W) {
		cin>>i;
		FOR(y,i) {
			if(A[y][x]==1) return _P("0\n");
			A[y][x]=0;
		}
		if(A[i][x]==0) return _P("0\n");
		A[i][x]=0;
	}
	ll ret=1;
	FOR(y,H) FOR(x,W) if(A[y][x]==-1) ret=ret*2%mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}