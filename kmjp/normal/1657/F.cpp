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

int N,Q;
vector<int> E[400005];
int P[21][400005],D[400005];

vector<pair<int,pair<char,char>>> V[404040];

void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

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
UF<808080> uf;

int pat[404040];
int take[808080];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	assert(N<=400000);
	assert(Q<=400000);
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	FOR(i,Q) {
		cin>>x>>y>>s;
		x--,y--;
		int l=lca(x,y);
		vector<int> A,B;
		while(x!=l) {
			A.push_back(x);
			x=P[0][x];
		}
		A.push_back(l);
		while(y!=l) {
			B.push_back(y);
			y=P[0][y];
		}
		reverse(ALL(B));
		FORR(b,B) A.push_back(b);
		FOR(j,s.size()) {
			V[A[j]].push_back({i,{s[j],s[s.size()-1-j]}});
		}
	}
	
	FOR(i,N) {
		int fix[26];
		MINUS(fix);
		FORR(v,V[i]) {
			if(v.second.first==v.second.second) fix[v.second.first-'a']=v.first;
		}
		int f=-1,t;
		FOR(j,26) if(fix[j]>=0) f=j,t=fix[j];
		if(f>=0) {
			f+='a';
			FORR(v,V[i]) {
				if(v.second.first!=f&&v.second.second!=f) {
					cout<<"NO"<<endl;
					return;
				}
				if(v.second.first==f&&v.second.second==f) {
					continue;
				}
				if(v.second.first==f) {
					uf(v.first*2+1,2*Q);
				}
				else {
					uf(v.first*2,2*Q);
				}
			}
		}
		else {
			FOR(j,(int)V[i].size()-1) {
				if(V[i][j].second.first==V[i][j+1].second.first&&V[i][j].second.second==V[i][j+1].second.second) {
					uf(V[i][j].first*2,V[i][j+1].first*2);
					uf(V[i][j].first*2+1,V[i][j+1].first*2+1);
				}
				else if(V[i][j].second.first==V[i][j+1].second.second&&V[i][j].second.second==V[i][j+1].second.first) {
					uf(V[i][j].first*2,V[i][j+1].first*2+1);
					uf(V[i][j].first*2+1,V[i][j+1].first*2);
				}
				else if(V[i][j].second.first==V[i][j+1].second.first) {
					uf(V[i][j].first*2,V[i][j+1].first*2);
					uf(V[i][j].first*2+1,2*Q);
					uf(V[i][j+1].first*2+1,2*Q);
				}
				else if(V[i][j].second.first==V[i][j+1].second.second) {
					uf(V[i][j].first*2,V[i][j+1].first*2+1);
					uf(V[i][j].first*2+1,2*Q);
					uf(V[i][j+1].first*2,2*Q);
				}
				else if(V[i][j].second.second==V[i][j+1].second.first) {
					uf(V[i][j].first*2+1,V[i][j+1].first*2);
					uf(V[i][j].first*2,2*Q);
					uf(V[i][j+1].first*2+1,2*Q);
				}
				else if(V[i][j].second.second==V[i][j+1].second.second) {
					uf(V[i][j].first*2+1,V[i][j+1].first*2+1);
					uf(V[i][j].first*2,2*Q);
					uf(V[i][j+1].first*2,2*Q);
				}
				else {
					cout<<"NO"<<endl;
					return;
				}
				
			}
		}
	}

	FOR(i,Q) {
		if(uf[2*i]==uf[2*Q]&&uf[2*i+1]==uf[2*Q]) {
			cout<<"NO"<<endl;
			return;
		}
		if(uf[2*i]==uf[2*Q]) {
			take[uf[2*i+1]]=1;
			pat[i]=1;
		}
		else if(uf[2*i+1]==uf[2*Q]) {
			take[uf[2*i]]=1;
			pat[i]=0;
		}
		else if(take[uf[2*i]]) {
			pat[i]=0;
		}
		else if(take[uf[2*i+1]]) {
			pat[i]=1;
		}
		else {
			take[uf[2*i]]=1;
			pat[i]=0;
		}
	}
	string S;
	FOR(i,N) {
		if(V[i].empty()) {
			S+='a';
		}
		else {
			if(pat[V[i][0].first]==0) S+=V[i][0].second.first;
			else S+=V[i][0].second.second;
		}
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