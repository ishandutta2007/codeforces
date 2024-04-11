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
UF<500000> uf;

int H,W,K;
string S[52];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		cin>>S[y+1];
		S[y+1]="." + S[y+1] + ".";
	}
	S[0]=S[H+1]=string(W+2,'.');
	H+=2;
	W+=2;
	FOR(y,H) FOR(x,W-1) if(S[y][x]==S[y][x+1]) uf(y*60+x,y*60+x+1);
	FOR(y,H-1) FOR(x,W) if(S[y][x]==S[y+1][x]) uf(y*60+x,y*60+x+60);
	
	set<pair<int,int>> SS;
	FOR(y,H) FOR(x,W) if(uf[y*60+x]==y*60+x && S[y][x]=='.' && uf[y*60+x]!=uf[0]) {
		SS.insert({uf.count(y*60+x),y*60+x});
	}
	
	int ret=0;
	while(SS.size()>K) {
		ret += SS.begin()->first;
		FOR(y,H) FOR(x,W) if(SS.begin()->second==uf[y*60+x]) S[y][x]='*';
		SS.erase(SS.begin());
		
	}
	
	cout<<ret<<endl;
	FOR(y,H-2) cout<<S[y+1].substr(1,W-2)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}