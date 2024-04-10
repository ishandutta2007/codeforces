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

int T;
int N;
int A[2][202020];
vector<int> C[202020];

int vis[202020];
vector<int> P[2];

void dfs(int cur,int id) {
	if(vis[cur]) return;
	vis[cur]=1;
	P[id].push_back(cur);
	
	if(id==0) {
		int nex=A[1][cur];
		int i=0;
		if(C[nex][0]==N+cur) i++;
		int tar=C[nex][i];
		if(tar>=N) dfs(tar-N,1);
		else dfs(tar,0);
	}
	else {
		int nex=A[0][cur];
		int i=0;
		if(C[nex][0]==cur) i++;
		int tar=C[nex][i];
		if(tar>=N) dfs(tar-N,1);
		else dfs(tar,0);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) C[i].clear(),vis[i]=0;
		FOR(j,2) {
			FOR(i,N) {
				cin>>A[j][i];
				A[j][i]--;
				C[A[j][i]].push_back(j*N+i);
			}
		}
		FOR(i,N) if(C[i].size()!=2) break;
		if(i<N) {
			cout<<-1<<endl;
			continue;
		}
		vector<int> V;
		FOR(i,N) {
			x=A[0][i];
			if(C[x][0]<N&&C[x][1]<N&&vis[i]==0) {
				P[0].clear();
				P[1].clear();
				dfs(i,0);
				
				if(P[0].size()>P[1].size()) swap(P[0],P[1]);
				FORR(p,P[0]) V.push_back(p);
			}
		}
		
		
		
		cout<<V.size()<<endl;
		FORR(v,V) cout<<(v+1)<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}