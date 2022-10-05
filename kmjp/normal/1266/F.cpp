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

int N;
vector<pair<int,int>> E[505050];
map<int,int> M[505050];
int MD[505050];

int ret[505050];

int dfs(int cur,int pre) {
	int i;
	int ma=0;
	FOR(i,E[cur].size()) if(E[cur][i].first!=pre) {
		E[cur][i].second=dfs(E[cur][i].first,cur)+1;
		ma=max(ma,E[cur][i].second);
	}
	return ma;
}
void dfs2(int cur,int pre,int pard) {
	vector<int> V;
	V.push_back(0);
	V.push_back(0);
	int i;
	FOR(i,E[cur].size()) {
		if(E[cur][i].first==pre) E[cur][i].second=pard;
		V.push_back(E[cur][i].second);
	}
	sort(ALL(V));
	reverse(ALL(V));
	FOR(i,E[cur].size()) if(E[cur][i].first!=pre) {
		if(V[0]==E[cur][i].second) dfs2(E[cur][i].first,cur,V[1]+1);
		else dfs2(E[cur][i].first,cur,V[0]+1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back({y-1,0});
		E[y-1].push_back({x-1,0});
	}
	dfs(0,0);
	dfs2(0,0,0);
	
	FOR(i,N) {
		ret[1]=max(ret[1],1+(int)E[i].size());
		vector<int> V;
		FORR(e,E[i]) V.push_back(e.second);
		sort(ALL(V));
		FORR(v,V) M[i][-v]++;
		FOR(x,V.size()) {
			ret[V[x]*2]=max((int)ret[V[x]*2],(int)V.size()-x);
			if(x<V.size()-1&&V[x+1]>V[x]) {
				ret[V[x]*2+1]=max((int)ret[V[x]*2+1],(int)V.size()-x);
			}
			else {
				ret[V[x]*2-1]=max((int)ret[V[x]*2-1],(int)V.size()-x);
			}
		}
	}
	
	FOR(i,N) FORR(e,E[i]) if(e.first<i) {
		x=i;
		y=e.first;
		if(M[x].size()<M[y].size()) swap(x,y);
		FORR(m,M[y]) M[x][m.first]+=m.second;
		int sum=0;
		FORR(m,M[x]) {
			sum+=m.second;
			ret[-m.first*2]=max(ret[-m.first*2],sum-2);
		}
		FORR(m,M[y]) M[x][m.first]-=m.second;
	}
	
	
	for(i=N;i>=1;i--) ret[i]=max({ret[i],ret[i+2],1});
	for(i=1;i<=N;i++) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}