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
int A[101010];
int loose[101010];
int L[301][301];
vector<pair<int,int>> F;
vector<int> E[301];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]>300) {
			F.push_back({A[i],i});
		}
		else {
			E[A[i]].push_back(i);
		}
	}
	
	sort(ALL(F));
	reverse(ALL(F));
	
	FORR(e,F) {
		x=e.second;
		loose[x]=1;
		for(i=1;x+i*A[x]<N;i++) {
			y=x+i*A[x];
			if(A[y]>A[x] && loose[y]) loose[x]=0;
		}
		for(i=1;x-i*A[x]>=0;i++) {
			y=x-i*A[x];
			if(A[y]>A[x] && loose[y]) loose[x]=0;
		}
		if(loose[x]) {
			for(i=1;i<=300;i++) L[i][x%i]=1;
		}
	}
	for(i=300;i>=1;i--) {
		FORR(e,E[i]) loose[e]=L[i][e%i]^1;
		FORR(e,E[i]) if(loose[e]) {
			for(j=1;j<i;j++) L[j][e%j]=1;
		}
	}
	
	FOR(i,N) _P("%c",'A'+loose[i]);
	_P("\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}