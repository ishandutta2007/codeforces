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
int A[202020];
ll ret;

void dfs(int L,int R,int level) {
	if(R-L<2 || level<0) return;
	int M,i;
	M=lower_bound(A+L,A+R,1<<level)-A;
	
	for(i=M;i<R;i++) A[i]^=1<<level;
	if(L<M &&M<R) {
		int mi=1<<30;
		for(i=L;i<M;i++) {
			int X=M,Y=R;
			int cur=0;
			for(int l=level-1;l>=0;l--) {
				int Z=lower_bound(A+X,A+Y,cur+(1<<l))-A;
				
				if(Z==X) {
					cur+=1<<l;
				}
				else if(Z==Y) {
				}
				else if(A[i]&(1<<l)) {
					X=Z;
					cur+=1<<l;
				}
				else {
					Y=Z;
				}
			}
			
			mi=min(mi,A[i]^A[X]);
		}
		ret+=(1LL<<level)+mi;
	}
	dfs(L,M,level-1);
	dfs(M,R,level-1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	
	dfs(0,N,29);
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}