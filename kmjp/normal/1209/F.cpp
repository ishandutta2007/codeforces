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

int N,M;
int C[101010];
vector<int> E[1001010][10];
int D[1001010];
ll R[1001010];
ll mo=1000000007;
int nex;
ll p10[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,9) p10[i+1]=p10[i]*10;
	
	cin>>N>>M;
	nex=N+1;
	for(i=1;i<=M;i++) {
		cin>>x>>y;
		
		int step=1;
		while(p10[step]<=i) step++;
		vector<int> V;
		V.push_back(x);
		FOR(j,step-1) V.push_back(nex++);
		V.push_back(y);
		FOR(j,step) {
			E[V[j]][i/p10[step-1-j]%10].push_back(V[j+1]);
			E[V[step-j]][i/p10[step-1-j]%10].push_back(V[step-j-1]);
		}
	}
	
	FOR(i,nex+1) D[i]=1<<30;
	D[1]=0;
	queue<vector<int>> Q;
	Q.push({1});
	while(Q.size()) {
		queue<vector<int>> NQ;
		while(Q.size()) {
			vector<int> V=Q.front();
			Q.pop();
			
			FOR(i,10) {
				vector<int> nex;
				FORR(v,V) {
					FORR(e,E[v][i]) if(D[e]>D[v]+1) {
						D[e]=D[v]+1;
						R[e]=(R[v]*10+i)%mo;
						nex.push_back(e);
					}
				}
				if(nex.size()) NQ.push(nex);
			}
			
		}
		
		swap(NQ,Q);
	}
	
	for(i=2;i<=N;i++) cout<<R[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}