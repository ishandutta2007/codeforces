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
int A[2020202];
int num[1<<21];

int ok(int mask) {
	int i;
	for(i=N-1;i>=0;i--) {
		int cm=mask&A[i];
		int lef=mask^cm;
		if(num[lef]>=2) return 1;
		if(num[cm]>=2) continue;
		num[cm]++;
		vector<int> V;
		V.push_back(cm);
		int j;
		FOR(j,21) {
			vector<int> V2;
			FORR(v,V) if(v&(1<<j)) {
				int nv=(v^(1<<j));
				if(num[nv]<2) {
					num[nv]++;
					V2.push_back(nv);
				}
			}
			FORR(v,V2) V.push_back(v);
		}
		
	}
	return 0;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	
	FOR(i,N) scanf("%d",&A[i]);
	
	
	int ret=0;
	for(i=20;i>=0;i--) {
		ZERO(num);
		if(ok(ret|(1<<i))) ret|=1<<i;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}