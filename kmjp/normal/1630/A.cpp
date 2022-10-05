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


int T,N,K;
int A[1<<16],B[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		if(N==4&&K==3) {
			cout<<-1<<endl;
			continue;
		}
		FOR(i,N/2) A[i]=i;
		FOR(i,N/2) B[N/2-1-i]=N/2+i;
		
		if(K==N-1) {
			swap(A[0],B[1]);
			swap(B[1],B[2]);
		}
		else {
			if(K<N/2) swap(B[0],B[K]);
			else swap(B[0],A[N-1-K]);
		}
		
		FOR(i,N/2) cout<<A[i]<<" "<<B[i]<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}