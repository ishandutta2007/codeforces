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
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<3030> uf;

int N;
ll X[2020],Y[2020],A[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int cand=-1;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>A[i];
		A[i]--;
		uf(i,A[i]);
		if(i!=A[i]) cand=i;
	}
	
	if(cand==-1) return _P("0\n");
	
	vector<pair<double,int>> V;
	FOR(i,N) if(i!=cand && i!=A[i]) {
		double d=atan2(Y[i]-Y[cand],X[i]-X[cand]);
		V.push_back({d,i});
	}
	sort(ALL(V));
	if(V.empty()) {
		cout<<0<<endl;
		return;
	}
	double pi=4*atan(1);
	V.push_back({V[0].first+2*pi,V[0].second});
	vector<pair<int,int>> R;
	
	FOR(i,V.size()-1) {
		if(V[i+1].first-V[i].first>=pi) continue;
		if(uf[V[i].second]!=uf[V[i+1].second]) {
			R.push_back({V[i].second,V[i+1].second});
			uf(V[i].second,V[i+1].second);
			swap(A[V[i].second],A[V[i+1].second]);
		}
	}
	
	while(A[cand]!=cand) {
		x=A[cand];
		R.push_back({cand,x});
		swap(A[cand],A[x]);
	}
	
	
	cout<<R.size()<<endl;
	FORR(r,R) cout<<(r.first+1)<<" "<<(r.second+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}