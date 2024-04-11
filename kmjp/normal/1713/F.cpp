#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
int B[1505050];
int C[1505050];
int A[1505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int M=1,X=0;
	while(M<N) M*=2,X++;
	FOR(i,N) {
		cin>>B[M-1-i];
		C[i]=B[M-1-i];
	}
	
	FOR(i,X) FOR(j,M) if(j&(1<<i)) C[j]^=C[j^(1<<i)];
	FOR(i,M-N) C[M-1-i]=0;
	FOR(i,X) FOR(j,M) if(j&(1<<i)) C[j]^=C[j^(1<<i)];
	FOR(i,M-N) B[i]=C[M-1-i];
	FOR(i,X) FOR(j,M) if(j&(1<<i)) B[j]^=B[j^(1<<i)];
	
	FOR(i,N) cout<<B[N-1-i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}