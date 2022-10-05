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

int N,K;
int P[303030];
int nex[303030],pre[303030];

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
UF<303030> uf;
vector<int> line[303030];

vector<int> E[303030];
int in[303030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>P[i+1];
	FOR(i,K) {
		cin>>x>>y;
		if(nex[x]) return _P("0\n");
		if(pre[y]) return _P("0\n");
		nex[x]=y;
		pre[y]=x;
		uf(x,y);
	}
	
	for(i=1;i<=N;i++) if(pre[i]==0) {
		x=i;
		set<int> did;
		while(x) {
			if(P[x]&&uf[x]==uf[P[x]]) {
				if(did.count(P[x])==0) return _P("0\n");
			}
			line[uf[i]].push_back(x);
			did.insert(x);
			x=nex[x];
			
		}
	}
	
	for(i=1;i<=N;i++) if(P[i]&&uf[i]!=uf[P[i]]) {
		E[uf[P[i]]].push_back(uf[i]);
		in[uf[i]]++;
	}
	
	vector<int> ret;
	queue<int> Q;
	for(i=1;i<=N;i++) if(uf[i]==i&&in[i]==0) Q.push(i);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,line[x]) ret.push_back(e);
		FORR(e,E[x]) {
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
	}
	if(ret.size()==N) {
		FORR(e,ret) cout<<e<<" ";
		cout<<endl;
	}
	else {
		cout<<0<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}