#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N;
string S;
const ll mo=998244353;

ll dp[202020][2][2][2][2][2][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	dp[0][1][1][1][0][0][0]=1;
	FOR(i,N) {
		int sa2,sa1,sa0,is2,is1,is0;
		int t2,t1,t0;
		FOR(sa2,2) FOR(sa1,2) FOR(sa0,2) FOR(t2,2) FOR(t1,2) FOR(t0,2) {
			int nsa2=sa2;
			int nsa1=sa1;
			int nsa0=sa0;
			if(sa2) {
				if(S[i]=='0'&&t2) continue;
				if(S[i]=='1'&&t2==0) nsa2=0;
			}
			if(sa1) {
				if(t1>t2) continue;
				if(t1<t2) nsa1=0;
			}
			if(sa0) {
				if(t0>t1) continue;
				if(t0<t1) nsa0=0;
			}
			
			
			FOR(is2,2) FOR(is1,2) FOR(is0,2) if(dp[i][sa2][sa1][sa0][is2][is1][is0]) {
				int nis2=is2;
				int nis1=is1;
				int nis0=is0;
				if(t2==0&&t1&&t0) nis2=1;
				if(t2==1&&t1==0&&t0==0) nis2=1;
				if(t1==0&&t2&&t0) nis1=1;
				if(t1==1&&t2==0&&t0==0) nis1=1;
				if(t0==0&&t2&&t1) nis0=1;
				if(t0==1&&t2==0&&t1==0) nis0=1;
				(dp[i+1][nsa2][nsa1][nsa0][nis2][nis1][nis0]+=dp[i][sa2][sa1][sa0][is2][is1][is0])%=mo;
			}
			
		}
	}
	
	ll ret=dp[N][1][0][0][1][1][1]+dp[N][0][0][0][1][1][1];
	cout<<ret*6%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}