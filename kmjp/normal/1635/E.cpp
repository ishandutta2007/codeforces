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
UF<404040> uf;

int N,M;
int T[202020],A[202020],B[202020];
vector<int> E[404040];
vector<int> E2[404040];
int in[404040];
int C[404040];
int X[202020];

void dfs(int cur,int col) {
	if(C[cur]!=-1) {
		if(C[cur]!=col) {
			cout<<"NO"<<endl;
			exit(0);
		}
		return;
	}
	C[cur]=col;
	FORR(e,E[cur]) dfs(e,col^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>T[i]>>A[i]>>B[i];
		A[i]--,B[i]--;
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
	};
	MINUS(C);
	FOR(i,N) if(C[i]==-1) dfs(i,0);
	FOR(i,M) {
		if(T[i]==1) {
			if(C[A[i]]==0) {
				E2[A[i]].push_back(B[i]);
				in[B[i]]++;
			}
			else {
				E2[B[i]].push_back(A[i]);
				in[A[i]]++;
			}
		}
		else {
			if(C[A[i]]==1) {
				E2[A[i]].push_back(B[i]);
				in[B[i]]++;
			}
			else {
				E2[B[i]].push_back(A[i]);
				in[A[i]]++;
			}
		}
	}
	
	MINUS(X);
	queue<int> Q;
	int cur=0;
	FOR(i,N) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		X[x]=cur++;
		FORR(e,E2[x]) {
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
	}
	FOR(i,N) if(X[i]==-1) {
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	FOR(i,N) {
		if(C[i]==0) cout<<"L ";
		else cout<<"R ";
		cout<<X[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}