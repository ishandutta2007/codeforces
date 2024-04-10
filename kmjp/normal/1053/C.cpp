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
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

ll mo=1000000007;
template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	V add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};

BIT<ll,20> WS;
BIT_mod<ll,20> LS,RS;


int N,Q;
int A[202020],W[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,N) {
		scanf("%d",&A[i]);
		A[i]-=i;
	}
	FOR(i,N) {
		scanf("%d",&W[i]);
		WS.add(i,W[i]);
		LS.add(i,1LL*A[i]*W[i]%mo);
		RS.add(i,((1LL<<30)-A[i])*W[i]%mo);
	}
	while(Q--) {
		int L,R;
		scanf("%d%d",&L,&R);
		if(L<0) {
			L=-L;
			L--;
			WS.add(L,-W[L]);
			LS.add(L,(mo-1LL*A[L]*W[L]%mo)%mo);
			RS.add(L,(mo-((1LL<<30)-A[L])*W[L]%mo)%mo);
			W[L]=R;
			WS.add(L,W[L]);
			LS.add(L,1LL*A[L]*W[L]%mo);
			RS.add(L,((1LL<<30)-A[L])*W[L]%mo);
		}
		else {
			L--;
			R--;
			ll s=WS(R)-WS(L-1);
			ll ts=WS(L-1)+s/2;
			x=WS.lower_bound(ts);
			if(x>L) x--;
			while(x<R && WS(R)-WS(x)>=WS(x)-WS(L-1)) x++;
			int best=x;
			ll ret=RS(best-1)-RS(L-1)-(WS(best-1)-WS(L-1))%mo*((1LL<<30)-A[best]);
			ret+=LS(R)-LS(best)-(WS(R)-WS(best))%mo*(A[best]);
			cout<<(ret%mo+mo)%mo<<endl;
			
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}