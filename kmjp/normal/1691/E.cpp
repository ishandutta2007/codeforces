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
UF<202020> uf;
int T,N;
int C[101010];
ll L[101010],R[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		uf.reinit(N);
		vector<pair<ll,int>> ev;
		FOR(i,N) {
			cin>>C[i]>>L[i]>>R[i];
			L[i]=L[i]*1000000-1-i;
			R[i]=R[i]*1000000+1+i;
			ev.push_back({L[i],i});
			ev.push_back({R[i],i});
		}
		set<int> V[2];
		sort(ALL(ev));
		FORR2(a,i,ev) {
			if(a==R[i]) {
				V[C[i]].erase(i);
			}
			else {
				V[C[i]].insert(i);
				if(V[C[i]^1].size()) {
					int ma=-1;
					FORR(v,V[C[i]^1]) {
						if(ma==-1) {
							ma=v;
						}
						else {
							if(R[v]>R[ma]) ma=v;
						}
						uf(i,v);
					}
					V[C[i]^1]={ma};
				}
			}
		}
		
		
		
		int ret=0;
		FOR(i,N) if(uf[i]==i) ret++;
		cout<<ret<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}