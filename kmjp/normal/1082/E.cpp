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

int N,C;
int A[1010101];
int S[1010101];
vector<int> V[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&C);
	FOR(i,N) {
		scanf("%d",&A[i]);
		S[i+1]=S[i]+(A[i]==C);
		if(A[i]!=C) V[A[i]].push_back(i+1);
	}
	
	int ma=S[N];
	for(i=1;i<=500000;i++) if(V[i].size()) {
		int ok=1;
		int cur=1;
		int mi=0;
		for(j=1;j<V[i].size();j++) {
			cur-=S[V[i][j]]-S[V[i][j-1]];
			mi=min(mi,cur);
			cur++;
			ok=max(ok,cur-mi);
		}
		ma=max(ma,S[N]+ok);
		
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}