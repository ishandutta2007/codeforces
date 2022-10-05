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

UF<5050> uf;
int N;
int SR,SC;
int TR,TC;
string S[51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>SR>>SC>>TR>>TC;
	SR--;
	SC--;
	TR--;
	TC--;
	FOR(y,N) cin>>S[y];
	FOR(y,N) FOR(x,N) if(S[y][x]=='0') {
		if(y&&S[y-1][x]=='0') uf(y*50+x,(y-1)*50+x);
		if(x&&S[y][x-1]=='0') uf(y*50+x,y*50+x-1);
	}
	
	int mi=1<<20;
	if(uf[SR*50+SC]==uf[TR*50+TC]) mi=0;
	FOR(y,N) FOR(x,N) if(uf[y*50+x]==uf[SR*50+SC]) {
		int y2,x2;
		FOR(y2,N) FOR(x2,N) if(uf[y2*50+x2]==uf[TR*50+TC]) {
			mi=min(mi,(y2-y)*(y2-y)+(x2-x)*(x2-x));
		}
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}