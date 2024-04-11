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

int N,M,K;
int NG[1010101];
int cnt[1010101];
int A[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&K);
	FOR(i,M) {
		scanf("%d",&x);
		cnt[x]=1;
	}
	int ma=0;
	for(i=1;i<N;i++) {
		if(cnt[i] && i) cnt[i]+=cnt[i-1];
		ma=max(ma,cnt[i]);
	}
	for(int x=1;x<=K;x++) scanf("%d",&A[x]);
	if(cnt[0]) return _P("-1\n");
	ll ret=1LL<<60;
	for(int x=ma+1;x<=K;x++) {
		int cur=0;
		ll cost=0;
		while(cur<N) {
			cur-=cnt[cur];
			cur+=x;
			cost+=A[x];
		}
		ret=min(ret,cost);
	}
	if(ret==1LL<<60) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}