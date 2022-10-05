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
vector<string> S;
int num[101010];
map<int,int> M[101010];
ll ret;

const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		ITR(it,s) if((cur=V[cur][*it+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		sort(S.begin(),S.end());
		ITR(it,S) {
			int cur=0;
			ITR(c,(*it)) {
				if(V[cur][*c+1]==0) V.push_back(vector<int>(NUMC+1)),V[cur][*c+1]=V.size()-1;
				cur=V[cur][*c+1];
			}
		}
	}
	
	void dfs(int cur,int depth) {
		int i;
		for(int i=1;i<=NUMC;i++) if(V[cur][i]) {
			int x=V[cur][i];
			dfs(x,depth+1);
			
			if(M[cur].size()>M[x].size()) swap(M[cur],M[x]);
			FORR(m,M[x]) M[cur][m.first]+=m.second;
		}
		
		if(num[cur]) {
			ret+=depth;
			M[cur][depth]++;
		}
		else if(depth && M[cur].size()) {
			int d=M[cur].rbegin()->first;
			ret-=d-depth;
			if(--M[cur][d]==0) M[cur].erase(d);
			M[cur][depth]++;
		}
	}
	
	
};
Trie T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='a';
		S.push_back(s);
	}
	
	T.create(S);
	
	FOR(i,N) num[T.find(S[i])]++;
	T.dfs(0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}