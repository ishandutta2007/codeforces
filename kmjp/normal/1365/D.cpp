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

int T;
int H,W;
string S[51];

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		UF<2500> uf;
		cin>>H>>W;
		FOR(y,H) cin>>S[y];
		FOR(y,H) FOR(x,W) if(S[y][x]=='B') {
			if(y&&S[y-1][x]=='.') S[y-1][x]='#';
			if(x&&S[y][x-1]=='.') S[y][x-1]='#';
			if(y+1<H&&S[y+1][x]=='.') S[y+1][x]='#';
			if(x+1<W&&S[y][x+1]=='.') S[y][x+1]='#';
		}
		FOR(y,H) FOR(x,W) if(S[y][x]!='#') {
			if(y&&S[y-1][x]!='#') uf(y*50+x,(y-1)*50+x);
			if(x&&S[y][x-1]!='#') uf(y*50+x,y*50+x-1);
		}
		int ng=0;
		FOR(y,H) FOR(x,W) if(S[y][x]=='B') if(uf[y*50+x]==uf[(H-1)*50+(W-1)]) ng=1;
		FOR(y,H) FOR(x,W) if(S[y][x]=='G') if(uf[y*50+x]!=uf[(H-1)*50+(W-1)]) ng=1;
		if(ng==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}