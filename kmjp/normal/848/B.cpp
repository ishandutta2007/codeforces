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

int N,H,W;
int G[101010],P[101010],T[101010];
int X[101010],Y[101010];
int TX[101010],TY[101010];
int R[101010];
vector<pair<int,int>> E[402020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>H;
	FOR(i,N) {
		cin>>G[i]>>P[i]>>T[i];
		R[i]=i;
		if(G[i]==1) {
			X[i]=P[i];
			Y[i]=-T[i];
			TX[i]=X[i];
			TY[i]=H;
		}
		else {
			Y[i]=P[i];
			X[i]=-T[i];
			TY[i]=Y[i];
			TX[i]=W;
		}
		
		E[X[i]+Y[i]+200000].push_back({X[i],i});
	}
	
	FOR(i,401000) if(E[i].size()>1) {
		sort(ALL(E[i]));
		FOR(x,E[i].size()) if(E[i][x].first>0) break;
		FOR(y,E[i].size()) R[E[i][y].second]=E[i][(x+y)%E[i].size()].second;
	}
	
	FOR(i,N) _P("%d %d\n",TX[R[i]],TY[R[i]]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}