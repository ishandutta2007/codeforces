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
int P[202020];
int rev[202020];
ll ret;
void dfs(int L,int R,set<int>& S) {
	if(R-L<=2) return;
	set<int> S2;
	
	int M=rev[*S.rbegin()];
	S.erase(*S.rbegin());
	int x;
	if(M-L>R-M) {
		for(x=M+1;x<R;x++) {
			S.erase(P[x]);
			S2.insert(P[x]);
		}
		for(x=M+1;x<R;x++) {
			ret+=S.count(P[M]-P[x]);
		}
		dfs(L,M,S);
		dfs(M+1,R,S2);
	}
	else {
		for(x=L;x<M;x++) {
			S.erase(P[x]);
			S2.insert(P[x]);
		}
		for(x=L;x<M;x++) {
			ret+=S.count(P[M]-P[x]);
		}
		dfs(L,M,S2);
		dfs(M+1,R,S);
	}
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<int> V;
	FOR(i,N) {
		cin>>P[i];
		rev[P[i]]=i;
		V.insert(P[i]);
	}
	dfs(0,N,V);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}