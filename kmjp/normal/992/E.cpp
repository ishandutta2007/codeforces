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

int N,Q;
int A[202020];
const int DI=450;
unordered_map<ll,int> S[DI];
ll tsum[450];

void update(int id) {
	int j;
	ll sum=0;
	S[id].clear();
	FOR(j,DI) {
		if(id*DI+j>=N) break;
		if(A[id*DI+j]>=sum) S[id][A[id*DI+j]-sum]=id*DI+j;
		sum+=A[id*DI+j];
	}
	tsum[id]=sum;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,DI) update(i);
	
	while(Q--) {
		cin>>x>>y;
		x--;
		A[x]=y;
		update(x/DI);
		
		ll sum=0;
		FOR(i,DI) {
			if(S[i].empty()) continue;
			if(S[i].count(sum)) {
				cout<<S[i][sum]+1<<endl;
				break;
			}
			sum+=tsum[i];
		}
		
		if(i==DI) cout<<-1<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}