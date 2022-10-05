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
ll K;
ll A[3030];
ll TL[3030],TR[3030];
ll S=0;
ll num=0;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll ret=-1;
	FOR(i,N) {
		cin>>A[i];
	}
	FOR(i,N+1) {
		int LN=0,RN=0;
		ll LS=0,RS=0;
		FOR(j,i) {
			if(A[j]==0) LN++;
			else LS+=A[j];
		}
		for(j=i;j<N;j++) {
			if(A[j]==0) RN++;
			else RS-=A[j];
		}
		
		ll la=LS-K*LN;
		ll lb=LS+K*LN;
		ll ra=RS-K*RN;
		ll rb=RS+K*RN;
		
		if(ra>lb||la>rb) continue;
		TL[i]=TR[i]=min(lb,rb);
		for(j=i-1;j>=0;j--) {
			if(A[j]==0) {
				TL[j]=TL[j+1]-K;
				TR[j]=TR[j+1]+K;
			}
			else {
				TL[j]=TL[j+1]-A[j];
				TR[j]=TR[j+1]-A[j];
			}
		}
		for(j=i;j<N;j++) {
			if(A[j]==0) {
				TL[j+1]=TL[j]-K;
				TR[j+1]=TR[j]-K;
			}
			else {
				TL[j+1]=TL[j]+A[j];
				TR[j+1]=TR[j]+A[j];
			}
		}
		ll tmi=0;
		
		ll cur=0;
		FOR(j,i) {
			if(A[j]==0) {
				cur=max(cur-K,TL[j+1]);
			}
			else {
				cur+=A[j];
			}
			tmi=min(tmi,cur);
		}
		cur=0;
		for(j=N-1;j>=i;j--) {
			if(A[j]==0) {
				cur=max(cur-K,TL[j]);
			}
			else {
				cur-=A[j];
			}
			tmi=min(tmi,cur);
		}
		
		ret=max(ret,TL[i]-tmi+1);
	}
	
	
	cout<<ret<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}