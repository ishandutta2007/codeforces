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
ll A,B,T;
string S;
ll R[505050],L[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>T;
	cin>>S;
	FORR(r,S) r=r=='w';
	
	for(i=1;i<N;i++) R[i]=R[i-1]+1+A+B*S[i];
	for(i=1;i<N;i++) L[i]=L[i-1]+1+A+B*S[N-i];
	L[N]=R[N]=1LL<<60;
	
	T-=1+B*S[0];
	if(T<0) return _P("0\n");
	int ret=1;
	ret=max(ret,1+(lower_bound(R,R+N,T+1)-R)-1);
	ret=max(ret,1+(lower_bound(L,L+N,T+1)-L)-1);
	for(i=1;i<N;i++) if(T-R[i]-A*i>0) ret=max(ret,1+i+(lower_bound(L,L+N,T-R[i]-A*i+1)-L-1));
	for(i=1;i<N;i++) if(T-L[i]-A*i>0) ret=max(ret,1+i+(lower_bound(R,R+N,T-L[i]-A*i+1)-R-1));
	ret=min(ret,N);
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}