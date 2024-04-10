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
string A,B;
int cnt[202020];

ll p2[202020];
ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,201000) p2[i+1]=p2[i]*2%mo;
	
	
	cin>>N>>M;
	cin>>A>>B;
	reverse(ALL(A));
	for(i=M-1;i>=0;i--) {
		cnt[i]+=cnt[i+1];
		cnt[i]+=B[M-1-i]=='1';
	}
	
	ll ret=0;
	FOR(i,N) if(A[i]=='1') (ret+=p2[i]*cnt[i])%=mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}