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

int H,W;
string S[1010];
UF<2020> uf;

vector<int> E[2020];
int in[2020];
int num[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) if(S[y][x]=='=') uf(y,H+x);
	FOR(y,H) FOR(x,W) {
		if(S[y][x]=='>') {
			if(uf[y]==uf[H+x]) return _P("No\n");
			E[uf[H+x]].push_back(uf[y]);
			in[uf[y]]++;
		}
		if(S[y][x]=='<') {
			if(uf[y]==uf[H+x]) return _P("No\n");
			E[uf[y]].push_back(uf[H+x]);
			in[uf[H+x]]++;
		}
	}
	
	queue<int> Q;
	FOR(i,H+W) if(uf[i]==i && in[i]==0) Q.push(i);
	
	int cur=1;
	while(Q.size()) {
		queue<int> P=Q;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			num[x]=cur;
		}
		cur++;
		while(P.size()) {
			x=P.front();
			P.pop();
			FORR(e,E[x]) {
				in[e]--;
				if(in[e]==0) Q.push(e);
			}
		}
	}
	FOR(i,H+W) if(uf[i]==i && num[i]==0) return _P("No\n");
	cout<<"Yes"<<endl;
	FOR(i,H) cout<<num[uf[i]]<<" ";
	cout<<endl;
	FOR(i,W) cout<<num[uf[H+i]]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}