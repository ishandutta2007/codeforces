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

string S;
int N,K;
ll mo=1000000007;

int cnt[2030];
ll from[2][2030];
ll to[2][2030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	N=S.size();
	
	if(K==0) return _P("1\n");
	if(K==1) return _P("%d\n",N-1);
	
	from[1][0]=1;
	FORR(c,S) {
		ZERO(to);
		
		FOR(i,2010) {
			
			(to[0][i]+=from[0][i])%=mo;
			(to[0][i+1]+=from[0][i])%=mo;
			if(c=='1') {
				// take 1
				(to[1][i+1]+=from[1][i])%=mo;
				// take 0
				(to[0][i]+=from[1][i])%=mo;
			}
			else {
				(to[1][i]+=from[1][i])%=mo;
			}
			
		}
		
		swap(from,to);
	}
	
	ll ret=0;
	for(i=1;i<=2000;i++) {
		if(i>1) cnt[i]=1+cnt[__builtin_popcount(i)];
		if(i>1 && cnt[i]+1==K) ret+=from[0][i]+from[1][i];
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}