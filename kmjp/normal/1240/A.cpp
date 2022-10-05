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

int Q;
int N;
ll P[202020];
ll X,A,Y,B,AB;
ll K;

int ok(int v) {
	ll NAB=v/AB;
	ll NA=v/A-NAB;
	ll NB=v/B-NAB;
	if(v<=0) return 0;
	ll ret=0;
	int i;
	
	FOR(i,v) {
		if(ret>=K) return 1;
		if(NAB) {
			NAB--;
			ret+=P[i]*(X+Y);
		}
		else if(NA) {
			NA--;
			ret+=P[i]*X;
		}
		else if(NB) {
			NB--;
			ret+=P[i]*Y;
		}
		else break;
	}
	return ret>=K;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		FOR(i,N) {
			cin>>P[i];
			P[i]/=100;
		}
		sort(P,P+N);
		reverse(P,P+N);
		cin>>X>>A;
		cin>>Y>>B;
		if(X<Y) swap(X,Y), swap(A,B);
		cin>>K;
		
		AB=A*B/__gcd(A,B);
		
		int ret=N;
		if(ok(N)==0) {
			cout<<-1<<endl;
		}
		else {
			for(i=20;i>=0;i--) {
				if(ok(ret-(1<<i))) ret-=1<<i;
			}
			cout<<ret<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}