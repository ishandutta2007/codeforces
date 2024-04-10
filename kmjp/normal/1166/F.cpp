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
	UF() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<105050> uf[205];

int N,M,C,Q;
map<int,int> PC[101010];
string T[101010];
int num[101010],X[101010],Y[101010],Z[101010],U[101010],V[101010],R[101010];
int id[101010],tid=1;
vector<int> cand;

void add(int a,int b,int c) {
	
	int i;
	FOR(i,tid) {
		if(PC[a].count(c)==0 && i&&id[a]==i) uf[i](b,0);
		if(PC[b].count(c)==0 && i&&id[b]==i) uf[i](a,0);
		if(PC[a].count(c)) uf[i](b,PC[a][c]);
		if(PC[b].count(c)) uf[i](a,PC[b][c]);
	}
	
	PC[a][c]=b;
	PC[b][c]=a;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>C>>Q;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>R[i];
		num[U[i]]++;
		num[V[i]]++;
	}
	FOR(i,Q) {
		cin>>T[i]>>X[i]>>Y[i];
		if(T[i]=="+") {
			cin>>Z[i];
			num[X[i]]++;
			num[Y[i]]++;
		}
	}
	
	for(i=1;i<=N;i++) if(num[i]>1000) id[i]=tid++;
	FOR(i,M) add(U[i],V[i],R[i]);
	
	FOR(i,Q) {
		if(T[i]=="?") {
			x=X[i];
			y=Y[i];
			if(uf[0][x]==uf[0][y]) {
				cout<<"Yes"<<endl;
			}
			else if(id[y] && uf[id[y]][x]==uf[id[y]][0]) {
				cout<<"Yes"<<endl;
			}
			else if(id[y]==0) {
				int ok=0;
				FORR(m,PC[y]) if(uf[0][x]==uf[0][m.second]) ok=1;
				if(ok) {
					cout<<"Yes"<<endl;
				}
				else {
					cout<<"No"<<endl;
				}
			}
			else {
				cout<<"No"<<endl;
			}
		}
		else {
			add(X[i],Y[i],Z[i]);;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}