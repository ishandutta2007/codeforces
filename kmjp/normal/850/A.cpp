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

int N;
int A[1010],B[1010],C[1010],D[1010],E[1010];
vector<vector<int>> V;
int dist[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> CC;
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i]>>C[i]>>D[i]>>E[i], CC.push_back(i);
	FOR(y,N) FOR(x,y) {
		dist[x][y]=(A[y]-A[x])*(A[y]-A[x])+(B[y]-B[x])*(B[y]-B[x])+(C[y]-C[x])*(C[y]-C[x])+(D[y]-D[x])*(D[y]-D[x])+(E[y]-E[x])*(E[y]-E[x]);
		dist[y][x]=dist[x][y];
		V.push_back({dist[x][y],x,y});
	}
	
	sort(ALL(V));
	FORR(v,V) {
		vector<int> M;
		FORR(c,CC) {
			x=v[1],y=v[2];
			if(c==x || c==y) M.push_back(c);
			else {
				if(dist[c][x]+dist[c][y]<=dist[x][y]) M.push_back(c);
			}
		}
		
		CC=M;
	}
	_P("%d\n",CC.size());
	FOR(i,CC.size()) _P("%d%c",CC[i]+1,(i==CC.size()-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}