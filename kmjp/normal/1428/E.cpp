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

int N,K;
int A[101010];
int C[101010];

ll sp(int L,int D) {
	int x=L/D;
	int lef=L%D;
	
	ll ret=0;
	if(lef==0) {
		ret=1LL*x*x*D;
	}
	else {
		ret=1LL*x*x*(D-lef)+1LL*(x+1)*(x+1)*lef;
	}
	return ret;
	
	
}

ll nex(int cur) {
	if(C[cur]==A[cur]) return -(1LL<<60);
	return sp(A[cur],C[cur])-sp(A[cur],C[cur]+1);
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	priority_queue<pair<ll,int>> Q;
	FOR(i,N) {
		cin>>A[i];
		C[i]=1;
		Q.push({nex(i),i});
	}
	
	while(K>N) {
		K--;
		auto a=Q.top();
		Q.pop();
		x=a.second;
		C[x]++;
		Q.push({nex(x),x});
	}
	
	ll ret=0;
	FOR(i,N) ret+=sp(A[i],C[i]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}