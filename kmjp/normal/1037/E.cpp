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

int N,M,K;
int A[202020],B[202020];
unordered_set<int> E[202020];
int ok[202020];
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		E[A[i]].insert(B[i]);
		E[B[i]].insert(A[i]);
	}
	set<pair<int,int>> S;
	FOR(i,N) {
		ok[i]=1;
		S.insert({E[i].size(),i});
	}
	int cur=N;
	
	for(i=M-1;i>=0;i--) {
		while(S.size()) {
			if(S.begin()->first>=K) break;
			x=S.begin()->second;
			S.erase(S.begin());
			if(ok[x]) {
				ok[x]=0;
				cur--;
				FORR(e,E[x]) {
					S.erase({E[e].size(),e});
					E[e].erase(x);
					S.insert({E[e].size(),e});
				}
				E[x].clear();
			}
		}
		ret[i]=cur;
		
		if(E[A[i]].count(B[i])) {
			S.erase({E[A[i]].size(),A[i]});
			E[A[i]].erase(B[i]);
			S.insert({E[A[i]].size(),A[i]});
		}
		if(E[B[i]].count(A[i])) {
			S.erase({E[B[i]].size(),B[i]});
			E[B[i]].erase(A[i]);
			S.insert({E[B[i]].size(),B[i]});
		}
		
	}
	
	
	FOR(i,M) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}