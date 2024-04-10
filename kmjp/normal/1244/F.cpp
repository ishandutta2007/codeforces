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


int N,K;
string S;
int F[202020],NF;
int D[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,N) {
		if(S[i]==S[(i+1)%N] || S[i]==S[(i+N-1)%N]) F[i]=1, NF++;
	}
	
	if(NF==0) {
		if(K%2) {
			FORR(c,S) c='B'+'W'-c;
		}
		cout<<S<<endl;
		return;
	}
	
	FOR(i,N) D[i]=1<<20;
	FOR(i,N) if(F[i]) {
		int cur=0;
		FOR(j,N) {
			if(F[(i+j)%N]==1) cur=0;
			else {
				cur++;
				D[(i+j)%N]=cur;
			}
		}
		cur=0;
		FOR(j,N) {
			if(F[(i+N-j)%N]==1) cur=0;
			else {
				cur++;
				D[(i+N-j)%N]=min(D[(i+N-j)%N],cur);
			}
		}
		
		break;
	}
	
	FOR(i,N) if(F[i]==0) {
		if(D[i]<=K) {
			if(D[i]%2==1) S[i]='B'+'W'-S[i];
		}
		else {
			if(K%2==1) S[i]='B'+'W'-S[i];
		}
	}
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}