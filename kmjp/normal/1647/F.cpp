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
int A[505050];

int L[505050],R[505050],M[505050][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	int ret=0;
	
	FOR(r,2) {
		reverse(A+1,A+N+1);
		int ma=1;
		FOR(i,N) if(A[i+1]>A[ma]) ma=i+1;
		
		for(i=1;i<=ma;i++) {
			L[i]=1<<30;
			if(A[i]>L[i-1]) L[i]=min(L[i],A[i-1]);
			if(A[i]>A[i-1]) L[i]=min(L[i],L[i-1]);
		}
		
		for(i=N;i>=ma;i--) {
			R[i]=1<<30;
			if(A[i]>R[i+1]) R[i]=min(R[i],A[i+1]);
			if(A[i]>A[i+1]) R[i]=min(R[i],R[i+1]);
		}
		
		M[ma][0]=L[ma];
		M[ma][1]=-1;
		for(i=ma+1;i<=N;i++) {
			M[i][0]=1<<30;
			M[i][1]=-1;
			
			if(A[i]<A[i-1]) M[i][0]=min(M[i][0],M[i-1][0]);
			if(A[i]<M[i-1][1]) M[i][0]=min(M[i][0],A[i-1]);
			if(A[i]>A[i-1]) M[i][1]=max(M[i][1],M[i-1][1]);
			if(A[i]>M[i-1][0]) M[i][1]=max(M[i][1],A[i-1]);
			if(M[i][1]>R[i]) ret++;
		}
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}