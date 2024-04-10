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

int T;
int N;
int A[3030];
vector<int> S[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		ll sum=0;
		FOR(i,N) {
			S[i].clear();
			FOR(j,N) if(A[i]==A[j]) S[i].push_back(j);
			if(S[i][0]==i) {
				ll a=S[i].size();
				sum+=a*(a-1)*(a-2)*(a-3)/24;
			}
		}
		
		FOR(x,N) for(y=x+1;y<N;y++) if(A[x]!=A[y]) {
			i=lower_bound(ALL(S[y]),x)-S[y].begin();
			j=S[x].end()-lower_bound(ALL(S[x]),y);
			sum+=i*j;
		}
		cout<<sum<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}