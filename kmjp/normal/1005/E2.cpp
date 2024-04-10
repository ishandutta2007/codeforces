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
int A[202020];

ll tot,mor,les;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bit[2];

int S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	
	tot=1LL*N*(N+1)/2;
	
	// more
	S[0]=202020;
	FOR(i,N) {
		if(A[i]>M) S[i+1]=S[i]+1;
		else S[i+1]=S[i]-1;
	}
	
	for(i=N-1;i>=0;i--) {
		bit[0].add(S[i+1],1);
		tot-=bit[0](1<<19)-bit[0](S[i]);
	}
	// less
	FOR(i,N) {
		if(A[i]<M) S[i+1]=S[i]+1;
		else S[i+1]=S[i]-1;
	}
	
	for(i=N-1;i>=0;i--) {
		bit[1].add(S[i+1],1);
		tot-=bit[1](1<<19)-bit[1](S[i]-1);
	}
	
	
	cout<<tot<<endl;
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}