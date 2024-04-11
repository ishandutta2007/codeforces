#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[101010],B[101010],C[101010],D[101010];
vector<int> VA,VB;
set<pair<int,int> > ST[500];
set<pair<int,int> > S[200000];
int from[101010],cost[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	VA.push_back(0);
	VA.push_back(1<<30);
	queue<int> Q;
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		VA.push_back(A[i]);
		VA.push_back(C[i]);
	}
	sort(ALL(VA));
	VA.erase(unique(ALL(VA)),VA.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(VA),A[i])-VA.begin();
		C[i]=lower_bound(ALL(VA),C[i])-VA.begin();
		if(A[i]||B[i]) {
			ST[A[i]/500].insert({B[i],i});
			S[A[i]].insert({B[i],i});
			cost[i]=101010;
		}
		else {
			cost[i]=0;
			from[i]=-1;
			Q.push(i);
		}
	}
	
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		
		x=C[cur];
		y=D[cur];
		FOR(i,x/500) {
			while(ST[i].size() && ST[i].begin()->first<=y) {
				int tar=ST[i].begin()->second;
				cost[tar] = cost[cur]+1;
				from[tar] = cur;
				Q.push(tar);
				S[A[tar]].erase({B[tar],tar});
				ST[i].erase(ST[i].begin());
			}
		}
		for(i=x/500*500;i<=x;i++) {
			while(S[i].size() && S[i].begin()->first<=y) {
				int tar=S[i].begin()->second;
				cost[tar] = cost[cur]+1;
				from[tar] = cur;
				Q.push(tar);
				ST[A[tar]/500].erase({B[tar],tar});
				S[i].erase(S[i].begin());
			}
		}
	}
	
	
	if(cost[N-1]>N) return _P("-1\n");
	vector<int> R;
	x=N-1;
	while(x>=0) {
		R.push_back(x);
		x=from[x];
	}
	_P("%d\n",R.size());
	FOR(i,R.size()) _P("%d ",R[R.size()-1-i]+1);
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}