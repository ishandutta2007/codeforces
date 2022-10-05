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

int T;
int N,A[303030];
int D[303030];
vector<int> P[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			P[i+1].clear();
		}
			
		FOR(i,N) {
			cin>>A[i];
			P[A[i]].push_back(i);
			D[i+1]=999999;
		}
		for(i=1;i<=N;i++) if(P[i].size()) {
			int ma=max(P[i][0]+1,N-P[i].back());
			FOR(j,P[i].size()-1) ma=max(ma,P[i][j+1]-P[i][j]);
			D[ma]=min(D[ma],i);
		}
		
		for(i=1;i<=N;i++) {
			if(i>1) D[i]=min(D[i],D[i-1]);
			if(D[i]==999999) cout<<-1<<" ";
			else cout<<D[i]<<" ";
			
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}