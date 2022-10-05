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
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<1000000> uf;

int H,W;
string S[3030];
int R[1010],C[1010],T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='#') R[y]++,C[x]++,T++;
	}
	
	if(T==0) return _P("0\n");
	FOR(y,H) if(R[y]==0) {
		FOR(x,W) if(C[x]==0) break;
		if(x==W) return _P("-1\n");
	}
	FOR(x,W) if(C[x]==0) {
		FOR(y,H) if(R[y]==0) break;
		if(y==H) return _P("-1\n");
	}
	
	
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='#') {
		if(y&&S[y-1][x]=='#') uf(y*1000+x,(y-1)*1000+x);
		if(x&&S[y][x-1]=='#') uf(y*1000+x,y*1000+x-1);
	}
	
	FOR(y,H) if(R[y]) {
		deque<int> D;
		FOR(x,W) {
			if(S[y][x]=='.') r=-1;
			else r=uf[y*1000+x];
			if(D.empty() || D.back()!=r) D.push_back(r);
		}
		while(D.size()&&D.front()==-1) D.pop_front();
		while(D.size()&&D.back()==-1) D.pop_back();
		if(D.size()>1) return _P("-1\n");
	}
	FOR(x,W) if(C[x]) {
		deque<int> D;
		FOR(y,H) {
			if(S[y][x]=='.') r=-1;
			else r=uf[y*1000+x];
			if(D.empty() || D.back()!=r) D.push_back(r);
		}
		while(D.size()&&D.front()==-1) D.pop_front();
		while(D.size()&&D.back()==-1) D.pop_back();
		if(D.size()>1) return _P("-1\n");
	}
	
	int num=0;
	FOR(y,H) FOR(x,W) if(S[y][x]=='#' && uf[y*1000+x]==y*1000+x) num++;
	cout<<num<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}