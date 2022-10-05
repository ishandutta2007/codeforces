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
int A[5050];
ll from[202][1010];
ll to[202][1010];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	
	from[0][0]=1;
	FOR(i,N) {
		int dif=i?A[i]-A[i-1]:0;
		ZERO(to);
		FOR(x,i+1) FOR(y,K+1) if(from[x][y] && y+dif*x<=K) {
			// same or add
			(to[x][y+dif*x] += (1+x)*from[x][y])%=mo;
			// open
			(to[x+1][y+dif*x] += from[x][y])%=mo;
			// close
			if(x) (to[x-1][y+dif*x] += x*from[x][y])%=mo;
		}
		swap(from,to);
	}
	
	ll ret=0;
	FOR(y,K+1) ret+=from[0][y];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}