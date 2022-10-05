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

int Q;
int N;
int T[202020];
int C[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		FOR(i,N) cin>>T[i];
		
		FOR(i,N) if(T[i]!=T[0]) break;
		
		if(i==N) {
			cout<<1<<endl;
			FOR(i,N) cout<<"1 ";
			cout<<endl;
			continue;
		}
		if(N%2==0) {
			cout<<2<<endl;
			FOR(i,N) cout<<(1+i%2)<<" ";
			cout<<endl;
			continue;
		}
		FOR(i,N) if(T[i]==T[(i+1)%N]) {
			FOR(j,N) C[(i+1+j)%N]=1+j%2;
			break;
		}
		
		if(i<N) {
			cout<<2<<endl;
			FOR(i,N) cout<<C[i]<<" ";
			cout<<endl;
			continue;
		}
		cout<<3<<endl;
		FOR(i,N-1) cout<<(1+i%2)<<" ";
		cout<<3<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}