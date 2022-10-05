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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<1100000> uf;
class SCC_ART {
public:
	static const int MV = 1100000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> low,num,isart,gr;
	vector<pair<int,int>> ES;
	vector<vector<int> > SC; // out
	vector<int> ART; // out
	vector<set<pair<int,int>> > BE; // out, Edgeset
	UF<MV> uf;
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { E[x].push_back(y); E[y].push_back(x);}
	void dfs(int cur,int pre) {
		low[cur]=num[cur]=++time;
		FORR(e,E[cur]) {
			if(e!=pre && num[e]<num[cur]) ES.push_back({min(e,cur),max(e,cur)});
			if(num[e]) low[cur]=min(low[cur],num[e]);
			else {
				dfs(e,cur);
				low[cur]=min(low[cur],low[e]);
				if((num[cur]==1&&num[e]>2) || (num[cur]!=1&&low[e]>=num[cur])) isart[cur]=1;
				if(low[e]>=num[cur]) {
					BE.push_back(set<pair<int,int>>());
					while(1) {
						pair<int,int> te=ES.back();
						ES.pop_back();
						BE.back().insert(te);
						if(min(cur,e)==te.first && max(cur,e)==te.second) break;
					}
					
				}
			}
		}
		if(isart[cur]) ART.push_back(cur);
	}
	void scc() {
		ART.clear();uf.reinit();SC.clear();BE.clear();ES.clear();
		low=num=isart=gr=vector<int>(NV,0);
		for(int i=0;i<NV;i++) if(!num[i]) time=0,dfs(i,-1);
		sort(ART.begin(),ART.end());
		for(int i=0;i<NV;i++) FORR(r,E[i]) if(isart[i]==0 && isart[r]==0) uf(i,r);
		for(int i=0;i<NV;i++) if(uf[i]==i) gr[i]=SC.size(), SC.push_back(vector<int>());
		for(int i=0;i<NV;i++) gr[i]=gr[uf[i]], SC[gr[uf[i]]].push_back(i);
	}
};

SCC_ART sb;
int mp[101010];


int N,M;
int X[101010],Y[101010];
vector<int> E[101010];
map<pair<int,int>,int> MP;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	sb.init(N);
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		X[i]--,Y[i]--;
		MP[{X[i],Y[i]}]=MP[{Y[i],X[i]}]=i+1;
		sb.add_edge(X[i],Y[i]);
	}
	
	sb.scc();
	vector<int> V;
	FORR(b,sb.BE) {
		set<int> S;
		FORR(e,b) S.insert(e.first),S.insert(e.second);
		if(S.size()==b.size()) {
			FORR(e,b) V.push_back(MP[{e.first,e.second}]);
		}
	}
	
	sort(ALL(V));
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}