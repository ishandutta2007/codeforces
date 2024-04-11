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

int N,Q;
vector<int> E[200005];
int P[21][200005],D[200005];


void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	cin>>Q;
	while(Q--) {
		cin>>k;
		vector<pair<int,int>> V;
		int lc=-1;
		FOR(i,k) {
			cin>>x;
			x--;
			V.push_back({-D[x],x});
			
			if(lc==-1) {
				lc=x;
			}
			else {
				lc=lca(x,lc);
			}
		}
		sort(ALL(V));
		vector<int> cand;
		
		
		
		int ok=1;
		FORR2(d,v,V) {
			if(v==lc) continue;
			if(cand.size()==0) {
				cand.push_back(v);
			}
			else if(cand.size()==1) {
				if(lca(cand[0],v)==v) continue;
				if(lca(cand[0],v)!=lc) {
					ok=0;
					break;
				}
				cand.push_back(v);
			}
			else {
				if(lca(cand[0],v)==v && lca(cand[1],v)==lc) continue;
				if(lca(cand[1],v)==v && lca(cand[0],v)==lc) continue;
				ok=0;
				break;
			}
		}
		if(ok==0) {
			cout<<"No"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}