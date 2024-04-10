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
ll C[101010][3];
int col[101010];
vector<int> V;
vector<int> E[101010];

void dfs(int cur,int pre) {
	V.push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,3) FOR(j,N) cin>>C[j][i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	FOR(i,N) if(E[i].size()>=3) return _P("-1\n");
	FOR(i,N) if(E[i].size()==1) {
		dfs(i,i);
		break;
	}
	
	dfs(0,0);
	
	vector<int> cand={0,1,2};
	vector<int> D;
	ll mi=1LL<<60;
	do {
		ll tot=0;
		FOR(i,N) tot+=C[V[i]][cand[i%3]];
		
		if(tot<mi) {
			mi=tot;
			D=cand;
		}
	} while(next_permutation(ALL(cand)));
	
	
	FOR(i,N) col[V[i]]=D[i%3];
	cout<<mi<<endl;
	FOR(i,N) cout<<col[i]+1<<" ";
	cout<<endl;
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}