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

int N;
int X[101010],Y[101010];
vector<int> XS,YS;
int RS[101010];
int CS[101010];

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
vector<int> cand[502020];
ll p2[202020];
ll ret;
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		XS.push_back(X[i]);
		YS.push_back(Y[i]);
	}
	p2[0]=1;
	FOR(i,201000) p2[i+1]=p2[i]*2%mo;
	
	sort(ALL(XS));
	sort(ALL(YS));
	XS.erase(unique(ALL(XS)),XS.end());
	YS.erase(unique(ALL(YS)),YS.end());
	FOR(i,N) {
		X[i]=lower_bound(ALL(XS),X[i])-XS.begin();
		Y[i]=lower_bound(ALL(YS),Y[i])-YS.begin();
		RS[Y[i]]++;
		CS[X[i]]++;
		uf(Y[i],200000+i);
		uf(100000+X[i],200000+i);
	}
	FOR(i,200000+N) cand[uf[i]].push_back(i);
	
	ret=1;
	FOR(i,200000+N) if(uf[i]==i) {
		int e=0,v=0,rc=0;
		FORR(c,cand[i]) {
			if(c<100000) e+=RS[c]-1, rc++;
			else if(c<200000) e+=CS[c-100000]-1, rc++;
			else v++;
		}
		
		if(v==0) continue;
		if(e>=v) {
			(ret *= p2[rc])%=mo;
		}
		else {
			(ret *= p2[rc]-1)%=mo;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}