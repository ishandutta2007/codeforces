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
const ll mo=1000000007;

ll from[1010];
ll to[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	from[0]=1;
	FOR(i,2*M) {
		ZERO(to);
		FOR(x,N+1) {
			for(y=max(1,x);y<=N;y++) (to[y]+=from[x])%=mo;
		}
		swap(from,to);
	}
	ll ret=0;
	FOR(i,N) ret+=from[i+1];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}