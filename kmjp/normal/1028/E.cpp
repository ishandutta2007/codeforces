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
ll B[202020];
ll C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>B[i];
	
	if(count(B,B+N,0)==N) {
		cout<<"YES"<<endl;
		FOR(i,N) cout<<1<<" ";
		cout<<endl;
		return;
	}
	if(count(B,B+N,0)==N-1) {
		FOR(i,N) if(B[i]) break;
		FOR(j,N) {
			if(B[j]==0) C[j]=B[i]*2;
			else C[j]=B[j];
		}
	}
	else {
		FOR(i,N) {
			if(B[(i+N-1)%N]<B[i]) break;
		}
		if(i==N) return _P("NO\n");
		
		C[i]=B[i];
		for(j=1;j<N;j++) {
			x=(i-j+N)%N;
			y=(i-j+N+1)%N;
			r=(i-j+N+2)%N;
			
			if(B[x]>=C[y]) {
				C[y]+=(B[x]-C[y]+1+C[r]-1)/C[r]*C[r];
			}
			C[x]=C[y]+B[x];
		}
	}
	
	cout<<"YES"<<endl;
	FOR(i,N) cout<<C[i]<<" ";
	cout<<endl;
	FOR(i,N) assert(B[i]==C[i]%C[(i+1)%N]);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}