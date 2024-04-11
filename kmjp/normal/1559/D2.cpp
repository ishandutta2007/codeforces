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

int N,M1,M2;

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
UF<404040> uf,uf2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M1>>M2;
	FOR(i,M1) {
		cin>>x>>y;
		x--,y--;
		uf(x,y);
	}
	FOR(i,M2) {
		cin>>x>>y;
		x--,y--;
		uf2(x,y);
	}
	
	vector<pair<int,int>> V;
	for(i=1;i<N;i++) {
		if(uf[0]!=uf[i]&&uf2[0]!=uf2[i]) {
			V.push_back({0,i});
			uf(0,i);
			uf2(0,i);
		}
	}
	vector<int> A,B;
	FOR(i,N) {
		if(uf[i]!=uf[0]) A.push_back(i);
		if(uf2[i]!=uf2[0]) B.push_back(i);
	}
	while(A.size()&&B.size()) {
		while(A.size()&&uf[A.back()]==uf[0]&&uf2[A.back()]==uf2[0]) A.pop_back();
		while(B.size()&&uf[B.back()]==uf[0]&&uf2[B.back()]==uf2[0]) B.pop_back();
		if(A.size()&&B.size()) {
			V.push_back({A.back(),B.back()});
			uf(A.back(),B.back());
			uf2(A.back(),B.back());
			A.pop_back();
			B.pop_back();
		}
		
	}
	
	cout<<V.size()<<endl;
	FORR2(a,b,V) cout<<a+1<<" "<<b+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}