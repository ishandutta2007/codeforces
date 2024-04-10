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

ll mo=998244353;
int N,K;

ll from[501][501];
ll to[501][501];
ll F[501];
ll T[501];
ll pat[501];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K;
	from[0][0]=1;
	FOR(i,N) {
		ZERO(to);
		FOR(x,N) FOR(y,N) {
			// same
			to[max(x,y+1)][y+1]+=from[x][y];
			if(to[max(x,y+1)][y+1]>=mo) to[max(x,y+1)][y+1]-=mo;
			// other
			to[max(x,1)][1]+=from[x][y];
			if(to[max(x,1)][1]>=mo) to[max(x,1)][1]-=mo;
		}
		
		swap(from,to);
	}
	
	ll ret=0;
	for(i=1;i<=N;i++) {
		FOR(x,N+1) pat[i]+=from[i][x];
		pat[i]%=mo;
		
		ZERO(F);
		if(i<K) F[1]=1;
		FOR(j,N-1) {
			ZERO(T);
			FOR(x,N+1) {
				if(x*i>=K) break;
				// same
				if((x+1)*i<K) {
					T[x+1]+=F[x];
					if(T[x+1]>=mo) T[x+1]-=mo;
				}
				if(i<K) {
					T[1]+=F[x];
					if(T[1]>=mo) T[1]-=mo;
				}
			}
			swap(F,T);
		}
		
		ll tot=0;
		FOR(x,N+1) tot+=F[x];
		(ret+=pat[i]*(tot%mo))%=mo;
		
	}
	
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}