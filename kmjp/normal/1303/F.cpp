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

class UF {
	public:
	int um; vector<int> par,rank,cnt;
	UF(int um_) {um=um_;par=rank=vector<int>(um,0); cnt=vector<int>(um,1); reinit();}
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


int H,W,Q;
int A[302][302];
int B[302][302];
int L[302][302];
vector<pair<int,int>> V[2020200];
int ret[2020202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&H,&W,&Q);
	FOR(i,Q) {
		scanf("%d%d%d",&y,&x,&j);
		V[j].push_back({y-1,x-1});
	}
	
	int st=0;
	UF uf(H*W);
	for(i=1;i<=2000000;i++) if(V[i].size()) {
		FOR(y,H) FOR(x,W) B[y][x]=A[y][x];
		uf.reinit();
		int num=0;
		FOR(j,V[i].size()) {
			y=V[i][j].first;
			x=V[i][j].second;
			if(B[y][x]!=i) {
				num++;
				B[y][x]=i;
				L[y][x]=j;
				if(y&&B[y-1][x]==i&&uf[y*W+x]!=uf[(y-1)*W+x]) num--, uf(y*W+x,(y-1)*W+x);
				if(y+1<H&&B[y+1][x]==i&&uf[y*W+x]!=uf[(y+1)*W+x]) num--, uf(y*W+x,(y+1)*W+x);
				if(x&&B[y][x-1]==i&&uf[y*W+x]!=uf[y*W+x-1]) num--, uf(y*W+x,y*W+x-1);
				if(x+1<W&&B[y][x+1]==i&&uf[y*W+x]!=uf[y*W+x+1]) num--, uf(y*W+x,y*W+x+1);
			}
			ret[st+j]=num;
		}
		uf.reinit();
		FOR(y,H) FOR(x,W) if(B[y][x]!=i) {
			if(y&&B[y-1][x]==B[y][x]) uf(y*W+x,(y-1)*W+x);
			if(x&&B[y][x-1]==B[y][x]) uf(y*W+x,y*W+x-1);
		}
		num=0;
		FOR(y,H) FOR(x,W) if(B[y][x]!=i && uf[y*W+x]==y*W+x) num++;
		for(j=V[i].size()-1;j>=0;j--) {
			ret[st+j]+=num;
			y=V[i][j].first;
			x=V[i][j].second;
			if(L[y][x]==j) {
				B[y][x]=A[y][x];
				num++;
				if(y&&B[y-1][x]==A[y][x]&&uf[y*W+x]!=uf[(y-1)*W+x]) num--, uf(y*W+x,(y-1)*W+x);
				if(y+1<H&&B[y+1][x]==A[y][x]&&uf[y*W+x]!=uf[(y+1)*W+x]) num--, uf(y*W+x,(y+1)*W+x);
				if(x&&B[y][x-1]==A[y][x]&&uf[y*W+x]!=uf[y*W+x-1]) num--, uf(y*W+x,y*W+x-1);
				if(x+1<W&&B[y][x+1]==A[y][x]&&uf[y*W+x]!=uf[y*W+x+1]) num--, uf(y*W+x,y*W+x+1);
			}
		}
		
		FOR(j,V[i].size()) {
			y=V[i][j].first;
			x=V[i][j].second;
			A[y][x]=i;
		}
		
		st+=V[i].size();
	}
	FOR(i,Q) _P("%d\n",ret[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}