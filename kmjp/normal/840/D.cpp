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

int N,Q;
int A[303030];
int L[303030],R[303030],K[303030];
int ret[303030];
vector<int> V[303030],sm,la;
int cnt[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,N) {
		scanf("%d",&A[i]);
		V[A[i]].push_back(i);
	}
	FOR(i,Q) {
		scanf("%d%d%d",&L[i],&R[i],&K[i]),L[i]--,ret[i]=-1;
		if(R[i]-L[i]>=2500) la.push_back(i);
		else sm.push_back(i);
	}
	FOR(i,N+1) if(V[i].size()>400) {
		FORR(j,la) if(ret[j]==-1 && V[i].size()>(R[j]-L[j])/K[j]) {
			x = lower_bound(ALL(V[i]),R[j])-lower_bound(ALL(V[i]),L[j]);
			if(x>(R[j]-L[j])/K[j]) ret[j]=i;
		}
	}
	
	FORR(r,sm) if(ret[r]==-1) {
		x=(R[r]-L[r])/K[r];
		for(j=L[r];j<R[r];j++) {
			cnt[A[j]]++;
			if((ret[r]==-1 || ret[r]>A[j]) && cnt[A[j]]>x) ret[r]=A[j];
		}
		for(j=L[r];j<R[r];j++) cnt[A[j]]--;
	}
	
	FOR(i,Q) _P("%d\n",ret[i]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}