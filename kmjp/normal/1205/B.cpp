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
ll A[101010];
int num[64];

vector<int> V[5000];
int mi=10101;

int D[150][150][150];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>A[i];
		if(A[i]==0) {
			i--;
			N--;
			continue;
		}
		FOR(x,62) if(A[i]&(1LL<<x)) {
			num[x]++;
			if(num[x]>=3) return _P("3\n");
		}
	}
	
	FOR(x,N) FOR(y,N) {
		if(A[x]&A[y]) V[x].push_back(y);
	}
	
	FOR(i,N) FOR(j,N) FOR(k,N) D[i][j][k]=10101;
	queue<int> Q;
	FOR(i,N) {
		D[i][i][i]=0;
		Q.push(i*1000000+i*1000+i);
	}
	
	while(Q.size()) {
		int s=Q.front()/1000000;
		int pre=Q.front()/1000%1000;
		int cur=Q.front()%1000;
		Q.pop();
		FORR(e,V[cur]) {
			if(e==pre || e==cur) continue;
			if(e==s) return _P("%d\n",D[s][pre][cur]+1);
			if(D[s][cur][e]>D[s][pre][cur]+1) {
				D[s][cur][e]=D[s][pre][cur]+1;
				Q.push(s*1000000+cur*1000+e);
			}
		}
	}
	
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}