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
int A[2020];
int B[2020];
ll SA,SB;

ll mi;
pair<int,int> P[2];

vector<pair<ll,int>> V[2];
vector<pair<ll,int>> V2[2];

ll cost(int x,int y) {
	ll na=SA-V[0][x].first+V[1][y].first;
	ll nb=SB+V[0][x].first-V[1][y].first;
	return abs(na-nb);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], SA+=A[i];
	cin>>M;
	FOR(i,M) cin>>B[i], SB+=B[i];
	
	mi=abs(SA-SB);
	FOR(x,N) FOR(y,M) {
		ll na=SA-A[x]+B[y];
		ll nb=SB-B[y]+A[x];
		if(abs(na-nb)<mi) mi=abs(na-nb), P[0]={x+1,y+1};
	}
	FOR(y,N) FOR(x,y) V2[0].push_back({A[x]+A[y],x*10000+y});
	FOR(y,M) FOR(x,y) V2[1].push_back({B[x]+B[y],x*10000+y});
	
	FOR(i,2) {
		sort(ALL(V2[i]));
		FORR(r,V2[i]) if(V[i].empty() || V[i].back().first!=r.first) V[i].push_back(r);
	}
	
	y=V[1].size()-1;
	FOR(x,V[0].size()) {
		while(y>0&&cost(x,y-1)<cost(x,y)) y--;
		while(y<V[1].size()-1&&cost(x,y+1)<cost(x,y)) y++;
		for(i=max(0,y-2);i<=min(y+2,(int)V[1].size()-1);i++) if(cost(x,i)<mi) {
			mi=cost(x,i);
			P[0]={1+V[0][x].second/10000,1+V[1][i].second/10000};
			P[1]={1+V[0][x].second%10000,1+V[1][i].second%10000};
		}
	}
	
	cout<<mi<<endl;
	cout<<(P[0].first>0)+(P[1].first>0)<<endl;
	FOR(i,2) if(P[i].first) cout<<P[i].first<<" "<<P[i].second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}