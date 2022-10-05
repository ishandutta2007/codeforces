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

int Q,N,K;
string S;
int ST[202020][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>K>>S;
		FOR(i,N) {
			if(S[i]=='R') x=0;
			if(S[i]=='G') x=1;
			if(S[i]=='B') x=2;
			x-=i;
			x=(x%3+3)%3;
			S[i]=x;
			ST[i+1][0]=ST[i][0]+(x!=0);
			ST[i+1][1]=ST[i][1]+(x!=1);
			ST[i+1][2]=ST[i][2]+(x!=2);
		}
		
		int mi=K;
		for(i=0;i+K<=N;i++) {
			mi=min(mi,ST[i+K][0]-ST[i][0]);
			mi=min(mi,ST[i+K][1]-ST[i][1]);
			mi=min(mi,ST[i+K][2]-ST[i][2]);
		}
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}