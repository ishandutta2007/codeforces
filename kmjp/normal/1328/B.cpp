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

int T;
ll N,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		ll L=1,R=N+1;
		while(R-L>=2) {
			ll M=(L+R)/2;
			if(M*(M-1)/2<=K) L=M;
			else R=M;
		}
		
		string S(N,'a');
		if(L*(L-1)/2==K) {
			S[N-1-(L-1)]='b';
			S[N-1-(L-2)]='b';
		}
		else {
			K-=L*(L-1)/2;
			L++;
			S[N-1-(L-1)]='b';
			S[N-1-(K-1)]='b';
		}
		
		
		cout<<S<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}