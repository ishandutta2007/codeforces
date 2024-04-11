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

int N,M;
vector<pair<int,int> > A;
vector<pair<int,int> > B;
int R[2][202020];
int C[101010],S[101010],ne[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		if(y==0) B.push_back({x,i});
		else A.push_back({x,i});
	}
	sort(ALL(A));
	sort(ALL(B));
	
	priority_queue<pair<int,int> > PQ;
	FOR(i,N-1) {
		R[0][A[i].second]=0;
		R[1][A[i].second]=1+i;
		C[i+1]=A[i].first;
		ne[i+1]=i+2;
	}
	FOR(i,N-1) {
		if(ne[i+1]<N) PQ.push({-C[ne[i+1]],i+1});
	}
	
	FOR(i,B.size()) {
		auto r=PQ.top();
		PQ.pop();
		if(-r.first>B[i].first) return _P("-1\n");
		R[0][B[i].second] = r.second;
		R[1][B[i].second] = ne[r.second];
		ne[r.second]++;
		if(ne[r.second]<N) PQ.push({-C[ne[r.second]],r.second});
	}
	
	
	
	FOR(i,M) _P("%d %d\n",R[0][i]+1,R[1][i]+1);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}