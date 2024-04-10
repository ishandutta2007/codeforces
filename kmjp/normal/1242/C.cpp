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

int K;
int N[15];
ll A[15][5000];
ll S[15],T;
map<ll,pair<int,int>> M;

pair<int,int> to[15][5050];
pair<int,int> R[15];
vector<pair<int,int>> V[1<<15];
int fix=0;

void dfs(int x,int y,int sx,int sy,int mask) {
	auto p=R[x];
	R[x]={A[x][y],to[x][y].first};
	
	if(mask&(1<<sx)) {
		if(x!=sx || y!=sy) return;
		
		V[mask].resize(K);
		int i;
		FOR(i,K) if(mask&(1<<i)) {
			V[mask][i].first=R[i].first;
			V[mask][R[i].second].second=i+1;
		}
		return;
		
	}
	
	int nx=to[x][y].first;
	int ny=to[x][y].second;
	if(nx!=-1 && (mask&(1<<nx))==0) {
		dfs(nx,ny,sx,sy,mask | (1<<nx));
	}
	R[x]=p;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	FOR(i,K) {
		cin>>N[i];
		FOR(j,N[i]) {
			cin>>A[i][j];
			S[i]+=A[i][j];
			T+=A[i][j];
			M[A[i][j]]={i,j};
		}
	}
	if(T%K) return _P("No\n");
	T/=K;
	
	FOR(i,K) {
		ll add=T-S[i];
		FOR(j,N[i]) {
			if(M.count(A[i][j]+add)) {
				to[i][j]=M[A[i][j]+add];
				if(to[i][j].first==i && to[i][j].second!=j) to[i][j]={-1,-1};
			}
			else {
				to[i][j]={-1,-1};
			}
		}
	}
	/*
	FOR(i,K) {
		FOR(j,N[i]) cout<<i<<j<<" "<<A[i][j]<<" "<<to[i][j].first<<" "<<to[i][j].second<<endl;
	}
	*/
	FOR(i,K) {
		FOR(j,N[i]) dfs(i,j,i,j,0);
	}
	
	
	int mask;
	FOR(mask,1<<K) if(V[mask].empty()) {
		for(int i=mask; i>0; i=(i-1)&mask) {
			j=mask^i;
			if(V[i].size() && V[j].size()) {
				V[mask].resize(K);
				FOR(r,K) {
					if(i&(1<<r)) V[mask][r]=V[i][r];
					else V[mask][r]=V[j][r];
				}
				break;
			}
		}
	}
	
	//FOR(mask,1<<K) if(V[mask].size()) cout<<mask<<endl;
	
	if(V[(1<<K)-1].size()) {
		cout<<"Yes"<<endl;
		FOR(i,K) cout<<V[(1<<K)-1][i].first<<" "<<V[(1<<K)-1][i].second<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}