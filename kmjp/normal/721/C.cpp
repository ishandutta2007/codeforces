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

int N,M,T;
int tim[5050][5050];
int from[5050][5050];
vector<pair<int,int>> E[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>T;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x].push_back({r,y});
	}
	FOR(x,N+1) FOR(y,N+1) tim[x][y]=T+1;
	priority_queue<pair<int,int>> Q;
	tim[1][1]=0;
	Q.push({0,1*10000+1});
	
	while(Q.size()) {
		int co=-Q.top().first;
		int num=Q.top().second/10000;
		int cur=Q.top().second%10000;
		Q.pop();
		if(co!=tim[num][cur]) continue;
		
		FORR(e,E[cur]) if(tim[num+1][e.second] > co+e.first) {
			tim[num+1][e.second] = co+e.first;
			from[num+1][e.second]= cur;
			Q.push({-tim[num+1][e.second],(num+1)*10000+e.second});
		}
	}
	
	vector<int> R;
	for(i=N;i>=1;i--) if(tim[i][N]<=T) {
		
		x=N;
		while(i>=1) {
			R.push_back(x);
			x = from[i][x];
			i--;
		}
		
		break;
	}
	
	reverse(ALL(R));
	_P("%d\n",R.size());
	FOR(i,R.size()) _P("%d%c",R[i],(i==R.size()-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}