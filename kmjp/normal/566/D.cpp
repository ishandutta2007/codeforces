#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
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
UF<500000> uf;

int N,Q;
set<int> uni;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) uni.insert(i);
	uni.insert(N);
	
	while(Q--) {
		cin>>i>>x>>y;
		x--,y--;
		
		if(i==1) {
			if(uf[x]!=uf[y]) uf(x,y);
		}
		else if(i==2) {
			if(x==y) continue;
			
			auto it1=uni.lower_bound(x);
			auto it2=uni.lower_bound(y+1);
			if(*it1>x) it1--;
			auto fir=it1;
			for(;it2!=it1;) {
				auto it3=it1;
				it3++;
				if(*it3<=y) uf(*it1,*it3);
				if(it1!=fir) it1=uni.erase(it1);
				else it1++;
			}
		}
		else if(i==3) {
			_P("%s\n",(uf[x]==uf[y])?"YES":"NO");
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}