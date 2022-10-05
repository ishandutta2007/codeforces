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

int N,M;
ll D[303030];
ll G[303030];
int vis[303030];

vector<pair<int,int>> E[202020];

class SCC {
public:
	static const int MV = 2025000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<NV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0,i; SC.clear(); SC.resize(NV); NUM.clear();
		assert(NV);
		FOR(i,NV) vis[i]=0; FOR(i,NV) if(!vis[i]) dfs(i); FOR(i,NV) vis[i]=0;
		for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};
SCC scc;

__int128 ext_gcd(__int128 p,__int128 q,__int128& x, __int128& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	__int128 g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

pair<__int128,__int128> crt(__int128 a1,__int128 mo1,__int128 a2,__int128 mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	__int128 g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<__int128,__int128>(-1,0); // N/A
	__int128_t lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<__int128,__int128>(-2,0); // overflow
	
	__int128_t v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

void dfs(int cur,ll sum) {
	if(D[cur]>=0) {
		G[scc.GR[cur]]=__gcd(G[scc.GR[cur]],abs(sum-D[cur]));
		return;
	}
	D[cur]=sum;
	FORR2(e,c,E[cur]) if(scc.GR[cur]==scc.GR[e]) dfs(e,sum+c);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	scc.init(N);
	FOR(i,M) {
		cin>>x>>y>>k;
		x--,y--;
		scc.add_edge(y,x);
		E[y].push_back({x,k});
	}
	scc.scc();
	MINUS(D);
	FOR(i,N) if(D[i]<0) dfs(i,0);
	
	int Q;
	cin>>Q;
	while(Q--) {
		int cur;
		ll S,T;
		cin>>cur>>S>>T;
		cur--;
		S=(T-S)%T;
		ll TG=G[scc.GR[cur]];
		
		if(S==0) {
			cout<<"YES"<<endl;
		}
		else {
			if(TG==0) {
				cout<<"NO"<<endl;
			}
			else {
				auto p=crt(0,TG,S,T);
				if(p.first>0) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
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