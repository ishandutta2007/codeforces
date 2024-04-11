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
int A[505];

ll hoge(ll v) {
	int j;
	ll cnt=0;
	if(A[0]<v) return 1LL<<50;
	FOR(j,N) {
		int B=A[j]/(v+1);
		int C=A[j]%(v+1);
		if(C==0) {
			cnt += B;
		}
		else if(v-C<=B) {
			cnt += B+1;
		}
		else {
			return 1LL<<50;
		}
	}
	return cnt;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll mi=0;
	FOR(i,N) cin>>A[i], mi+=A[i];
	sort(A,A+N);
	
	for(i=1;i<=1000000;i++) mi=min(mi,hoge(i));
	if(A[0]>=1000000) {
		for(i=1;i<=1000;i++) {
			mi=min(mi,hoge(A[N-1]/i));
			mi=min(mi,hoge(A[N-1]/i+1));
			mi=min(mi,hoge(A[N-1]/i-1));
		}
	}
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}