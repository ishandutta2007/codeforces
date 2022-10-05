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
int A[5050];
int L[5050],R[5050];
int LL[5050],RR[5050];
int S[5050];

ll dp[5050];
vector<pair<int,int>> cand[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,5001) L[i]=5000,R[i]=-1;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		L[A[i]]=min(L[A[i]],i);
		R[A[i]]=i;
	}
	for(i=0;i<=5000;i++) if(R[i]>=0) {
		LL[i]=L[i];
		RR[i]=R[i];
		x=y=L[i];
		while(x>LL[i] || y<RR[i]) {
			if(x>LL[i]) {
				x--;
				LL[i]=min(LL[i],L[A[x]]);
				RR[i]=max(RR[i],R[A[x]]);
			}
			if(y<RR[i]) {
				y++;
				LL[i]=min(LL[i],L[A[y]]);
				RR[i]=max(RR[i],R[A[y]]);
			}
		}
		set<int> s;
		for(x=LL[i];x<=RR[i];x++) {
			if(s.count(A[x])==0) {
				s.insert(A[x]);
				S[i] ^= A[x];
			}
		}
		cand[LL[i]].push_back({RR[i],S[i]});
	}
	
	FOR(i,N) {
		FORR(c,cand[i]) dp[c.first+1]=max(dp[c.first+1],dp[i]+c.second);
		dp[i+1]=max(dp[i],dp[i+1]);
	}
	
	cout<<*max_element(dp,dp+N+1)<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}