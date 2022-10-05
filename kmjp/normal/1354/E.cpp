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
int C[3];
vector<int> E[5050];

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

int col[5050];
vector<int> cand[2][5050];
pair<int,int> from[5050][5050];
string S;

void dfs(int cur,int id,int c) {
	if(col[cur]>=0) return;
	col[cur]=c;
	cand[c][id].push_back(cur);
	FORR(e,E[cur]) dfs(e,id,c^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,3) cin>>C[i];
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		E[y].push_back(x);
		uf(x*2,y*2+1);
		uf(x*2+1,y*2);
		if(uf[x*2]==uf[x*2+1]) return _P("NO\n");
	}
	
	MINUS(col);
	MINUS(from);
	from[0][0]={0,0};
	int pre=0;
	FOR(i,N) if(col[i]==-1) {
		dfs(i,i,0);
		for(j=N;j>=0;j--) if(from[pre][j].first!=-1) {
			from[i+1][j+cand[0][i].size()]={pre,0};
			from[i+1][j+cand[1][i].size()]={pre,1};
		}
		pre=i+1;
	}
	
	if(from[pre][C[1]].first==-1) return _P("NO\n");
	S.resize(N,'0');
	y=C[1];
	while(pre>0) {
		x=from[pre][y].first;
		i=from[pre][y].second;
		FORR(c,cand[i][pre-1]) S[c]='2', y--;
		pre=x;
	}
	
	
	
	FOR(i,N) if(S[i]=='0') {
		if(C[0]) C[0]--, S[i]='1';
		else S[i]='3';
	}
	cout<<"YES"<<endl;
	cout<<S<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}