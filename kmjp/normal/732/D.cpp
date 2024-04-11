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
int D[101010];
int A[101010];

int did[101010];
int P[101010];
int ok(int d) {
	if(d<=0) return 0;
	
	ZERO(did);
	int a=0;
	int i;
	int prac=0;
	for(i=d-1;i>=0;i--) {
		if(D[i]>0 && did[D[i]-1]==0) {
			prac+=A[D[i]-1];
			did[D[i]-1]=1;
			a++;
		}
		else {
			prac=max(0,prac-1);
		}
	}
	if(a<M || prac>0) return 0;
	return 1;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>D[i];
	FOR(i,M) cin>>A[i];
	
	if(ok(N)==0) return _P("-1\n");
	int ret=N;
	for(i=20;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}