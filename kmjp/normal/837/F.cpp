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
ll K,A[202020],B[202020];

int ok(ll turn) {
	if(N==2) {
		ll tot=A[0];
		tot*=turn;
		if(tot/turn!=A[0]) return 1;
		return tot+A[1]>=K;
	}
	else if(N==3) {
		ll tot=0;
		if(A[0]) {
			tot = turn*(turn+1);
			if(tot/turn!=turn+1) return 1;
			tot /= 2;
			if(tot*A[0]/tot!=A[0]) return 1;
			tot*=A[0];
			if(tot>=K) return 1;
		}
		if(A[1]*turn/turn!=A[1]) return 1;
		if(A[1]*turn>=K) return 1;
		
		return tot+A[1]*turn+A[2]>=K;
	}
	else {
		assert(0);
		return 0;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int first=1;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]) first=0;
		B[i]=A[i];
		if(first&&A[i]==0) i--, N--;
		if(A[i]>=K) return _P("0\n");
	}
	
	
	FOR(i,2000000) {
		ll tot=0;
		FOR(j,N) {
			tot+=B[j];
			if(tot>=K) return _P("%d\n",i+1);
			B[j]=tot;
		}
	}
	
	ll ret=(1LL<<60)-1;
	for(i=59;i>=0;i--) if(ok(ret-(1LL<<i))) ret-=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}