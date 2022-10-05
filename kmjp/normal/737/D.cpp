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
int A[4040];
ll S[4040];

int LL[4040][4040][2];
int RR[4040][4040][2];

vector<ll> memo;

void check(int L,int R,int K,int t) {
	if(R-L+1<K) return;
	if(LL[L][R][t]<=K && K<=RR[L][R][t]) return;
	LL[L][R][t]=min(LL[L][R][t],K);
	RR[L][R][t]=max(RR[L][R][t],K);
	if(t==0) {
		check(L+K,R,K,1);
		check(L+K+1,R,K+1,1);
	}
	else {
		check(L,R-K,K,0);
		check(L,R-(K+1),K+1,0);
	}
	
}

ll turn(int L,int R,int K,int t) {
	if(R-L+1<K) return 0;
	ll& ret=memo[(K-LL[L][R][t])+RR[L][R][t]];
	if(ret>-1LL<<60) return ret;
	
	if(t==0) {
		ret = turn(L+K,R,K,1) + S[L+K]-S[L];
		if(L+K+1<=R+1) ret = max(ret, turn(L+K+1,R,K+1,1) + S[L+K+1]-S[L]);
	}
	else {
		ret = turn(L,R-K,K,0) - (S[R+1]-S[R-K+1]);
		if(R-(K+1)>=L-1) ret = min(ret, turn(L,R-(K+1),K+1,0) - (S[R+1]-S[R-(K+1)+1]));
	}
	return ret;

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	FOR(x,N) FOR(y,N) LL[x][y][0]=LL[x][y][1]=N+1;
	FOR(x,N) FOR(y,N) RR[x][y][0]=RR[x][y][1]=-1;
	check(0,N-1,1,0);
	
	int tot=0;
	FOR(x,N) FOR(y,N) FOR(i,2) {
		if(LL[x][y][i]<=RR[x][y][i]) {
			int num = RR[x][y][i]-LL[x][y][i]+1;
			RR[x][y][i]=tot;
			tot+=num;
		}
	}
	
	memo.resize(tot+5);
	FORR(r,memo) r=-1LL<<60;
	
	cout<<turn(0,N-1,1,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}