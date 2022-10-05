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

ll N,S;
ll ret;
ll p[11];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p[0]=1;
	FOR(i,10) p[i+1]=p[i]*10;
	
	cin>>N;
	S=N+(N-1);
	
	int d=0;
	while(p[d+1]<=S) d++;
	
	if(N*2==p[d+1]) return _P("1\n");
	
	ll ret=0;
	for(int c=0;c<=8;c++) {
		ll P=(c+1)*p[d]-1;
		ll R=min(N,P-1);
		ll L=P/2+1;
		ret+=max(R-L+1,0LL);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}