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

int N,M,Q;
vector<int> E[3030];
vector<int> RE[3030];
int A[3030],B[13][3030];
int vis[3030];
vector<int> cand[3030];
int res[404040];
int S[404040],T[404040],K[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	scanf("%d%d%d",&N,&M,&Q);
	FOR(i,M) {
		scanf("%d%d",&x,&y);
		E[x-1].push_back(y-1);
		RE[y-1].push_back(x-1);
	}
	FOR(i,Q) {
		scanf("%d%d%d",&S[i],&T[i],&K[i]);
		S[i]--,T[i]--;
		cand[T[i]].push_back(i);
	}
	FOR(i,N) sort(ALL(E[i])), sort(ALL(RE[i]));
	
	MINUS(res);
	FOR(i,N) if(cand[i].size()) {
		ZERO(A);
		MINUS(B);
		
		queue<int> Q;
		Q.push(i);
		A[i]=1;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,RE[x]) if(A[e]==0) A[e]=1, Q.push(e);
		}
		B[0][i]=i;
		FOR(x,N) if(A[x]==1 && x!=i) {
			FORR(e,E[x]) if(A[e]==1) {
				B[0][x]=e;
				break;
			}
		}
		FOR(j,12) {
			FOR(x,N) if(B[j][x]>=0) B[j+1][x]=B[j][B[j][x]];
		}
		
		FORR(c,cand[i]) {
			int cur=S[c];
			if(A[cur]==0 || B[12][cur]!=i) continue;
			
			if(K[c]==1) {
				res[c]=cur+1;
				continue;
			}
			
			int num=K[c]-2;
			FOR(j,12) if(num&(1<<j)) cur=B[j][cur];
			
			if(cur==T[c]) continue;
			res[c]=B[0][cur]+1;
		}
		
		
	}
	
	FOR(i,Q) _P("%d\n",res[i]);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}