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
	vector<int> par,rank,val;
	UF() {rank=val=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {
		if(par[x]!=x) {
			int p=operator[](par[x]);
			val[x]^=dist(par[x]);
			par[x]=p;
		}
		return par[x];
	}
	int dist(int x) {
		operator[](x);
		return val[x];
	}
	void operator()(int x,int y,int v) {
		v^=dist(x)^dist(y);
		x=operator[](x);
		y=operator[](y);
		if(x==y) return;
		
		if(rank[x]>rank[y]) {
			par[x]=y;
			val[x]^=v;
		}
		else {
			rank[x]+=rank[x]==rank[y];
			par[y]=x;
			val[y]^=v;
		}
	}
};
UF<500000> uf;

int N;
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int last=0;
	cin>>N;
	while(N--) {
		int T,L,R,X;
		cin>>T>>L>>R;
		L^=last;
		R^=last;
		if(L>R) swap(L,R);
		R++;
		
		if(M.count(L)==0) M[L]=M.size();
		if(M.count(R)==0) M[R]=M.size();
		L=M[L];
		R=M[R];
		if(T==1) {
			cin>>X;
			X^=last;
			if(uf[L]!=uf[R]) uf(L,R,X);
		}
		else {
			if(uf[L]!=uf[R]) {
				cout<<-1<<endl;
				last=1;
			}
			else {
				last=uf.dist(L)^uf.dist(R);
				cout<<last<<endl;
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}