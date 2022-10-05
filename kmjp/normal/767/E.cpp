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
int C[101010],W[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>C[i];
	FOR(i,N) cin>>W[i];
	
	priority_queue<pair<int,int>> PQ;
	ll cost=0;
	FOR(i,N) {
		if(C[i]%100==0) continue;
		PQ.push({-W[i]*(100-C[i]%100),i});
		M-=C[i]%100;
		while(M < 0) {
			cost += -PQ.top().first;
			C[PQ.top().second]+=100-C[PQ.top().second]%100;
			M+=100;
			PQ.pop();
		}
	}
	cout<<cost<<endl;
	FOR(i,N) cout<<C[i]/100<<" "<<C[i]%100<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}