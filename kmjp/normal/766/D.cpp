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
UF<500000> uf;
map<string,int> S;
int N,M,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,N) cin>>s, S[s]=i;
	while(M--) {
		string A,B;
		cin>>i>>A>>B;
		x=S[A];
		y=S[B];
		if(i==1) {
			if(uf[x*2]==uf[y*2+1]) {
				cout<<"NO"<<endl;
			}
			else {
				cout<<"YES"<<endl;
				uf(x*2,y*2);
				uf(x*2+1,y*2+1);
			}
		}
		else {
			if(uf[x*2]==uf[y*2]) {
				cout<<"NO"<<endl;
			}
			else {
				cout<<"YES"<<endl;
				uf(x*2,y*2+1);
				uf(x*2+1,y*2);
			}
		}
	}
	while(Q--) {
		string A,B;
		cin>>A>>B;
		x=S[A];
		y=S[B];
		if(uf[x*2]==uf[y*2]) cout<<1<<endl;
		else if(uf[x*2]==uf[y*2+1]) cout<<2<<endl;
		else cout<<3<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}