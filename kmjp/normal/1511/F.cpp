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
const ll mo= 998244353;
vector<string> S;
const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		FORR(c,s) if((cur=V[cur][c+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		sort(S.begin(),S.end());
		FORR(s,S) {
			int cur=0;
			FORR(c,s) {
				if(V[cur][c+1]==0) V.push_back(vector<int>(NUMC+1)),V[cur][c+1]=V.size()-1;
				cur=V[cur][c+1];
			}
		}
	}
};

class ACmatch_num {
public:
	Trie t;
	vector<int> acc;
	int ma;
	void create(vector<string> S) {
		int i;
		ma=S.size();
		t.create(S);
		acc.clear();
		acc.resize(t.V.size());
		FOR(i,S.size()) acc[t.find(S[i])]=1;
	}
	
	int nex(int cur,int c) {
		return t.V[cur][c+1];
	}
};
ACmatch_num ac;

const int MAT=250;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

int id;
int mp[2020][2020];
vector<int> E[2020];
Mat A;

int dfs(int a,int b) {
	if(mp[a][b]>=0) return mp[a][b];
	mp[a][b]=id++;
	int cur=mp[a][b];
	int i;
	FOR(i,26) {
		int x=ac.nex(a,i);
		int y=ac.nex(b,i);
		if(x==0||y==0) continue;
		A.v[dfs(x,y)][cur]++;
		if(ac.acc[x]) A.v[dfs(0,y)][cur]++;
		if(ac.acc[y]) A.v[dfs(x,0)][cur]++;
		if(ac.acc[x]&&ac.acc[y]) A.v[dfs(0,0)][cur]++;
	}
	
	return cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	S.resize(N);
	FOR(i,N) {
		cin>>S[i];
		FORR(c,S[i]) c-='a';
	}
	ac.create(S);
	MINUS(mp);
	
	dfs(0,0);
	A=powmat(M,A);
	
	cout<<A.v[0][0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}