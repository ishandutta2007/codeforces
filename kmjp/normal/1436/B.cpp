#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N;

int A[101][101];

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ZERO(A);
		FOR(y,N-1) FOR(x,N-1) A[y][x]=1;
		for(x=N;;x++) {
			if(isprime(x)&&!isprime(x-(N-1))) {
				break;
			}
		}
		x-=N-1;
		FOR(i,N-1) A[N-1][i]=A[i][N-1]=x;
		for(i=x*(N-1)+1;;i++) {
			if(isprime(i)&&!isprime(i-x*(N-1))) {
				A[N-1][N-1]=i-x*(N-1);
				break;
			}
		}
		
		
		FOR(y,N) {
			FOR(x,N) cout<<A[y][x]<<" ";
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}