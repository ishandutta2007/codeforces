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
int A[202020];
int D[202020][2];
vector<int> E[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		D[i][0]=D[i][1]=202020;
		if(i+A[i]<N) E[i+A[i]].push_back(i);
		if(i-A[i]>=0) E[i-A[i]].push_back(i);
	}
	queue<int> Q;
	FOR(i,N) {
		if(i+A[i]<N && A[i+A[i]]%2!=A[i]%2) D[i][A[i]%2]=1;
		if(i-A[i]>=0 && A[i-A[i]]%2!=A[i]%2) D[i][A[i]%2]=1;
		if(D[i][A[i]%2]==1) Q.push(i*2+A[i]%2);
	}
	
	while(Q.size()) {
		x=Q.front()/2;
		y=Q.front()%2;
		Q.pop();
		FORR(e,E[x]) if(D[e][y]>D[x][y]+1) {
			D[e][y]=D[x][y]+1;
			Q.push(e*2+y);
		}
		
	}
	FOR(i,N) {
		if(D[i][0]==202020) D[i][0]=-1;
		if(D[i][1]==202020) D[i][1]=-1;
		cout<<D[i][A[i]%2]<<" ";
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}