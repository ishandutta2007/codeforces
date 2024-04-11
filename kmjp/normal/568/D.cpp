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

int N,K;
ll A[101010],B[101010],C[101010];
vector<pair<int,int> > P;
mt19937 rsrc;

// a1x+b1y=c1, a2x+b2y=c2
pair<double,double> cross(ll a1,ll b1,ll c1,ll a2,ll b2,ll c2) {
	if(a1*b2==a2*b1) return make_pair(1e100,1e100);
	double d=a1*b2-a2*b1;
	double x = b2*c1-b1*c2;
	double y = -a2*c1+a1*c2;
	return make_pair(x/d,y/d);
}

void dfs(vector<int> V,int L) {
	if(V.size()<=L) {
		FORR(r,V) P.push_back({r,-1});
		_P("YES\n%d\n",P.size());
		FORR(r,P) _P("%d %d\n",r.first,r.second);
		exit(0);
	}
	if(L==0) return;
	
	int i, id=rsrc()%V.size(),x;
	vector<pair<double,double> > CP(V.size()),CP2;
	CP2.reserve(V.size());
	FOR(i, V.size()) {
		CP[i]=cross(A[V[i]],B[V[i]],-C[V[i]],A[V[id]],B[V[id]],-C[V[id]]);
		if(CP[i].first!=1e100) CP2.push_back(CP[i]);
	}
	
	if(CP2.empty()) return;
	sort(CP2.begin(),CP2.end());
	int ma=0,cur=0;
	pair<double,double> cand,pre({1e100,1e100});
	FORR(r,CP2) {
		if(pre!=r) cur=0,pre=r;
		cur++;
		if(cur>ma) ma=cur,cand=r;
	}
	
	if(ma+1<V.size()/L) return;
	
	vector<int> V2;
	FOR(i,V.size()) {
		if(i==id) continue;
		if(CP[i]==cand) x=i;
		else V2.push_back(V[i]);
	}
	P.push_back({V[id],V[x]});
	dfs(V2,L-1);
	P.pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	rsrc=mt19937(time(NULL));
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i+1]>>B[i+1]>>C[i+1];
	
	FOR(i,60) {
		vector<int> V;
		FOR(j,N) V.push_back(j+1);
		dfs(V,K);
	}
	cout<<"NO"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}