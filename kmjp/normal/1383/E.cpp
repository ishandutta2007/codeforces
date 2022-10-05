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
string S;
ll dp[1010101];
int nex[1010101];
int num0[1010101];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>S;
	
	N=S.size();
	if(count(ALL(S),'1')==0) {
		cout<<N<<endl;
		return;
	}
	
	FOR(i,N) {
		if(S[i]=='0') {
			num0[i]=1;
			if(i) num0[i]+=num0[i-1];
		}
	}
	
	FOR(i,N+1) nex[i]=N;
	
	for(i=N-1;i>=0;i--) {
		// next 1
		if(nex[0]<N) dp[i]+=dp[nex[0]];
		// next 0
		if(nex[num0[i]+1]<N) dp[i]+=dp[nex[num0[i]+1]];
		// end
		if(num0[i]<=num0[N-1]) dp[i]++;
		
		dp[i]%=mo;
		nex[num0[i]]=i;
	}
	

	ll ret=0;
	FOR(i,N) if(S[i]=='1') {
		ret=dp[i]*(i+1)%mo;
		break;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}