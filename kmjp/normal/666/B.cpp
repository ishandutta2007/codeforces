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
vector<int> E[3030];
int dist[3030][3030];
vector<pair<int,int>> out[3030];
vector<pair<int,int>> in[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
	}
	FOR(x,N) FOR(y,N) dist[x][y]=101010;
	
	FOR(i,N) {
		dist[i][i]=0;
		queue<int> Q;
		Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(r,E[x]) if(dist[i][r]>dist[i][x]+1) dist[i][r]=dist[i][x]+1, Q.push(r);
		}
	}
	FOR(x,N) FOR(y,N) if(x!=y && dist[x][y]<=N) {
		out[x].push_back({dist[x][y],y});
		in[y].push_back({dist[x][y],x});
	}
	FOR(x,N) {
		sort(ALL(out[x]));
		reverse(ALL(out[x]));
		if(out[x].size()>3) out[x].resize(3);
		sort(ALL(in[x]));
		reverse(ALL(in[x]));
		if(in[x].size()>3) in[x].resize(3);
	}
	int ma=-1;
	int ret[4];
	FOR(x,N) FOR(y,N) if(x!=y && dist[x][y]<=N) {
		FORR(X,in[x]) {
			if(X.second==y) continue;
			FORR(Y,out[y]) {
				if(Y.second==x || Y.second==X.second) continue;
				int tot=dist[x][y]+X.first+Y.first;
				if(tot>ma) {
					ma=tot;
					ret[0]=X.second+1;
					ret[1]=x+1;
					ret[2]=y+1;
					ret[3]=Y.second+1;
				}
				break;
			}
		}
	}
	
	_P("%d %d %d %d\n",ret[0],ret[1],ret[2],ret[3]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}