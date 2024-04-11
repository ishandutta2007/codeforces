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

int N,M;
string S[51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	M=S[0].size();
	int mi=1<<20;
	
	FOR(i,M) {
		string T=S[0].substr(i)+S[0].substr(0,i);
		int tot=i;
		for(j=1;j<N;j++) {
			FOR(k,M) {
				string U=S[j].substr(k)+S[j].substr(0,k);
				if(T==U) break;
			}
			if(k==M) tot=1<<20;
			else tot+=k;
		}
		mi=min(mi,tot);
	}
	
	
	if(mi==1<<20) mi=-1;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}