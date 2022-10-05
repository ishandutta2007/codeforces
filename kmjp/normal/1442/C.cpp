#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
const ll mo=998244353;
vector<int> E[202020][2];

ll D[22][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x][0].push_back(y);
		E[y][1].push_back(x);
	}
	FOR(i,N) FOR(j,21) D[j][i]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	D[0][0]=0;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second%N;
		int num=Q.top().second/N;
		Q.pop();
		if(D[num][cur]!=co) continue;
		if(num<20) {
			if(co+(1<<num)<D[num+1][cur]) {
				D[num+1][cur]=co+(1<<num);
				Q.push({-D[num+1][cur],(num+1)*N+cur});
			}
		}
		FORR(e,E[cur][num%2]) if(co+1<D[num][e]) {
			D[num][e]=co+1;
			Q.push({-D[num][e],num*N+e});
		}
	}
	ll ret=1LL<<60;
	FOR(i,21) ret=min(ret,D[i][N-1]);
	if(ret==1LL<<60) {
		ll add=1<<19;
		int turn=0;
		set<int> cand;
		FOR(i,N) if(D[20][i]!=1LL<<60) cand.insert(i);
		ll sum=0;
		while(D[20][N-1]==1LL<<60) {
			turn^=1;
			add=add*2%mo;
			sum=(sum+add)%mo;
			FORR(c,cand) Q.push({-D[20][c],c});
			cand.clear();
			while(Q.size()) {
				ll co=-Q.top().first;
				int cur=Q.top().second;
				Q.pop();
				if(D[20][cur]!=co) continue;
				FORR(e,E[cur][turn]) if(co+1<D[20][e]) {
					D[20][e]=co+1;
					Q.push({-D[20][e],e});
					cand.insert(e);
				}
			}
		}
		ret=(sum+D[20][N-1])%mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}