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
int V[5];
int T[202020];
int did[202020];

int ok(int d,int n0,int n1) {
	int D[5]={d,d,d,0};
	int left=N,i;
	ZERO(did);
	for(i=N-1;i>=0;i--) if(did[i]==0 && D[2]&& T[i]<=V[2]) D[2]--, left--, did[i]=1;
	for(i=N-1;i>=0;i--) if(did[i]==0 && D[0]&&D[1]&& T[i]>V[1]&&T[i]<=V[0]+V[1]) D[0]--,D[1]--,left--, did[i]=1;
	D[1]+=n1;
	D[0]+=n0;
	for(i=N-1;i>=0;i--) if(did[i]==0 && D[1]&& T[i]<=V[1]) D[1]--, left--, did[i]=1;
	for(i=N-1;i>=0;i--) if(did[i]==0 && D[0]&& T[i]<=V[0]) D[0]--, left--, did[i]=1;
	
	return left==0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,3) cin>>V[i];
	FOR(i,N) cin>>T[i];
	sort(V,V+3);
	sort(T,T+N);
	if(T[N-1]>V[0]+V[1]+V[2]) return _P("-1\n");
	
	int ret=0;
	x=0;
	while(N && T[N-1]>V[1]+V[2]) { // need ABC
		assert(T[N-1]<=V[0]+V[1]+V[2]);
		N--, ret++;
	}
	int n0=0,n1=0;
	while(N && T[N-1]>V[0]+V[2]) { // need BC
		assert(T[N-1]<=V[1]+V[2]);
		N--, ret++,n0++;
	}
	while(N && T[N-1]>max(V[2],V[0]+V[1])) { // need AC
		assert(T[N-1]<=V[0]+V[2]);
		N--, ret++,n1++;
	}
	N-=x;
	FOR(i,N) T[i]=T[i+x];
	
	int ret2=(1<<20)-1;
	for(i=19;i>=0;i--) if(ok(ret2-(1<<i),n0,n1)) ret2-=1<<i;
	
	cout<<ret+ret2<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}