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



template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt,rem;

int N;
vector<int> E[505050];
int L[505050],R[505050];
int PE[505050];
int U[505050],V[505050],X[505050];
vector<int> Xs[505050];

int id;
void dfs(int cur,int pre) {
	L[cur]=id++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	R[cur]=id;
}

vector<pair<int,int>> cand;
vector<pair<int,int>> hist,hist2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>U[i]>>V[i]>>X[i];
		U[i]--,V[i]--,X[i]--;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
		Xs[X[i]].push_back(i);
	}
	dfs(0,0);
	FOR(i,N) bt.add(i,1);
	
	ll ret=0;
	FOR(i,N) if(Xs[i].size()) {
		cand.clear();
		hist.clear();
		hist2.clear();
		FORR(e,Xs[i]) {
			if(L[U[e]]<L[V[e]]) cand.push_back({L[V[e]],V[e]});
			else cand.push_back({L[U[e]],U[e]});
		}
		sort(ALL(cand));
		reverse(ALL(cand));
		cand.push_back({0,0});
		FORR2(l,v,cand) {
			ll a=bt(R[v]-1)-bt(L[v]-1);
			ll b=rem(R[v]-1)-rem(L[v]-1);
			ret+=a*b;
			if(v) {
				bt.add(L[v],-a);
				rem.add(L[v],a-b);
				hist.push_back({L[v],a});
				hist2.push_back({L[v],-a+b});
			}
		}
		FORR2(a,b,hist) bt.add(a,b);
		FORR2(a,b,hist2) rem.add(a,b);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}