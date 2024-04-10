#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,M,K;
vector<pair<int,int>> E[1010];
int U[1010],V[1010];
int A[1010],B[1010];

int D[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>r;
		U[i]--;
		V[i]--;
		E[U[i]].push_back({V[i],r});
		E[V[i]].push_back({U[i],r});
	}
	FOR(i,K) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
	}
	
	FOR(i,N) {
		FOR(j,N) D[i][j]=1<<29;
		D[i][i]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,i});
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(D[i][cur]!=co) continue;
			FORR(e,E[cur]) if(D[i][e.first]>co+e.second) {
				D[i][e.first]=co+e.second;
				Q.push({-D[i][e.first],e.first});
			}
		}
	}
	
	ll sum=1LL<<60;
	FOR(i,M) {
		ll tot=0;
		FOR(j,K) {
			tot+=min({D[A[j]][B[j]],D[A[j]][U[i]]+D[V[i]][B[j]],D[A[j]][V[i]]+D[U[i]][B[j]]});
		}
		sum=min(sum,tot);
	}
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}