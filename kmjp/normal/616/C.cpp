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
string S[3030];
string T[3030];

UF<2000000> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	S[0]=S[H+1]=string(W+2,'*');
	FOR(y,H) T[y]=string(W,'.');
	FOR(y,H) cin>>S[y+1], S[y+1]="*"+S[y+1]+"*";
	H+=2;
	W+=2;
	for(y=1;y<H-1;y++) {
		for(x=1;x<W-1;x++) if(S[y][x]=='.') {
			if(S[y][x+1]=='.') uf(y*1100+x,y*1100+x+1);
			if(S[y][x-1]=='.') uf(y*1100+x,y*1100+x-1);
			if(S[y+1][x]=='.') uf(y*1100+x,y*1100+x+1100);
			if(S[y-1][x]=='.') uf(y*1100+x,y*1100+x-1100);
		}
	}
	
	for(y=1;y<H-1;y++) {
		for(x=1;x<W-1;x++) if(S[y][x]=='*') {
			set<int> SS;
			if(S[y][x+1]=='.') SS.insert(uf[y*1100+x+1]);
			if(S[y][x-1]=='.') SS.insert(uf[y*1100+x-1]);
			if(S[y+1][x]=='.') SS.insert(uf[y*1100+x+1100]);
			if(S[y-1][x]=='.') SS.insert(uf[y*1100+x-1100]);
			ll ret=1;
			FORR(r,SS) ret+=uf.count(r);
			T[y-1][x-1]='0'+ret%10;
		}
	}
	FOR(y,H-2) cout<<T[y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}