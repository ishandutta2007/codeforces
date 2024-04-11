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

int N,M,D;
ll A[202020];
ll B[202020];
vector<int> V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	D=N/M;
	FOR(i,N) {
		cin>>A[i];
		B[i]=A[i];
		V[A[i]%M].push_back(i);
	}
	int L,R;
	ll ret=0;
	for(L=R=0;L<3*M;L++) {
		while(V[L%M].size()>D) {
			if(R<L) R=L;
			while(V[R%M].size()>=D) R++;
			int mi=min(V[L%M].size()-D,D-V[R%M].size());
			FOR(i,mi) {
				x=V[L%M].back();
				V[L%M].pop_back();
				A[x]+=R-L;
				ret+=R-L;
				V[R%M].push_back(x);
			}
		}
	}
	cout<<ret<<endl;
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}