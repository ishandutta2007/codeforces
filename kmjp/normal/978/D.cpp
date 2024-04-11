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
ll B[101010];
ll C[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>B[i];
	int mi=1<<20;
	
	if(N<=2) return _P("0\n");
	int L0=B[0]-1,R0=B[0]-1;
	int L1=B[1]-1,R1=B[1]+1;
	for(C[0]=B[0]-1;C[0]<=B[0]+1;C[0]++) {
		for(C[1]=B[1]-1;C[1]<=B[1]+1;C[1]++) {
			int tot=abs(B[0]-C[0])+abs(B[1]-C[1]);
			ll D=C[1]-C[0];
			ll cur=C[1];
			for(i=2;i<N;i++) {
				cur+=D;
				if(abs(cur-B[i])<=1) {
					tot+=abs(cur-B[i]);
				}
				else {
					tot=1<<20;
				}
			}
			mi=min(mi,tot);
			
		}
	}
	if(mi==1<<20) mi=-1;
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}