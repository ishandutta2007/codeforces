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

int N,K;
int A[101010];
int L[101010],R[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	
	if(K==1) {
		cout<<*min_element(A,A+N)<<endl;
	}
	else if(K==2) {
		FOR(i,N) L[i]=min((i?L[i-1]:1<<30),A[i]);
		for(i=N-1;i>=0;i--) R[i]=min((i==N-1?1<<30:R[i+1]),A[i]);
		int ma=-1<<30;
		FOR(i,N-1) ma=max(ma,max(L[i],R[i+1]));
		cout<<ma<<endl;
	}
	else if(K>=3) {
		cout<<*max_element(A,A+N)<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}