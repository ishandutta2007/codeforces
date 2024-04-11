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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

ll N;
ll A[101010];
long double ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	// inside perm;
	ll pat=0;
	for(ll len=1;len<=N;len++) {
		pat += N+1-len;
		ret += (N+1.0-len) * len*(len-1)/4;
	}
	for(i=N-1;i>=0;i--) {
		ret += pat*bt(A[i]);
		bt.add(A[i],1);
	}
	FOR(i,N) bt.add(A[i],-1);
	
	ll inv=0;
	for(i=N-1;i>=0;i--) {
		inv += bt(A[i]);
		ret -= inv;
		bt.add(A[i],N-i);
	}
	
	_P("%.12lf\n",(double)(ret/pat));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}