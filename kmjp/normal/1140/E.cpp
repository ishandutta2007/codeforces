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
vector<int> A[2];
ll mo=998244353;
ll dp[202020][3];

ll hoge1(int len) {
	int i;
	FOR(i,len+2) dp[i][0]=dp[i][1]=0;
	dp[0][0]=1;
	FOR(i,len) {
		dp[i+1][0]=dp[i][1]*(K-1)%mo;
		dp[i+1][1]=(dp[i][0]+dp[i][1]*(K-2))%mo;
	}
	return dp[len][1]*(K-1)%mo;
}

ll hoge2(int len) {
	int i;
	FOR(i,len+2) dp[i][0]=dp[i][1]=dp[i][2]=0;
	dp[0][0]=1;
	FOR(i,len) {
		dp[i+1][0]=(dp[i][1]+dp[i][2]*(K-2))%mo;
		dp[i+1][1]=(dp[i][0]+dp[i][2]*(K-2))%mo;
		dp[i+1][2]=(dp[i][0]+dp[i][1]+dp[i][2]*(K-3))%mo;
	}
	return (dp[len][0]+dp[len][2]*(K-2))%mo;
	
	
}

ll hoge(vector<int> V) {
	int i,L=V.size()+1,R=-1;
	
	FOR(i,V.size()) if(V[i]!=-1) {
		L=min(L,i);
		R=max(R,i);
	}
	
	ll ret;
	if(R==-1) {
		ret=K;
		FOR(i,V.size()-1) ret=ret*(K-1)%mo;
	} 
	else {
		ret=1;
		FOR(i,L) ret=ret*(K-1)%mo;
		for(i=V.size()-1;i>R;i--) ret=ret*(K-1)%mo;
		for(int cur=L+1;cur<=R;cur++) {
			if(V[cur]!=-1) {
				if(V[L]==V[cur]) ret=ret*hoge1(cur-L-1)%mo;
				else ret=ret*hoge2(cur-L-1)%mo;
				L=cur;
			}
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		A[i%2].push_back(x);
	}
	
	cout<<(hoge(A[0])*hoge(A[1]))%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}