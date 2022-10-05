#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int N,M;
int U[202020],V[202020];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf;
int dep[202020];
vector<int> E[202020];

void dfs(int cur,int pre,int d) {
	dep[cur]=d;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		string S;
		uf.reinit(N);
		vector<int> C;
		set<int> D;
		FOR(i,N) E[i].clear();
		FOR(i,M) {
			cin>>U[i]>>V[i];
			U[i]--,V[i]--;
			if(U[i]>V[i]) swap(U[i],V[i]);
			if(uf[U[i]]!=uf[V[i]]) {
				uf(U[i],V[i]);
				S+="0";
				E[U[i]].push_back(V[i]);
				E[V[i]].push_back(U[i]);
			}
			else {
				S+="1";
				C.push_back(i);
				D.insert(U[i]);
				D.insert(V[i]);
			}
		}
		if(C.size()==3&&D.size()==3) {
			dfs(0,0,0);
			x=*D.begin();
			FORR(v,D) if(dep[v]>dep[x]) x=v;
			FOR(i,M) if(S[i]=='0'&&((U[i]==x&&dep[V[i]]<dep[x])||(V[i]==x&&dep[U[i]]<dep[x]))) {
				FOR(j,3) if(U[C[j]]==x||V[C[j]]==x) {
					S[C[j]]='0';
					break;
				}
				assert(j<3);
				S[i]='1';
				break;
			}
			assert(i<M);
		}
		
		
		cout<<S<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}