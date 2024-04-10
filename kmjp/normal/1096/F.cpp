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
int A[202020];
ll mo=998244353;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) (bit[e-1]+=v)%=mo,e+=e&-e;}
};
BIT<ll,20> bt;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int uns=N;
	ll ret=0;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]>=0) {
			ret+=bt(N)-bt(A[i]);
			bt.add(A[i],1);
		}
	}
	ret%=mo;
	FOR(i,N) {
		bt.add(i+1,1);
		if(A[i]>=0) {
			bt.add(A[i],mo-2);
			uns--;
		}
	}
	(ret+=1LL*uns*(uns-1)%mo*((mo+1)/2)%mo*((mo+1)/2))%=mo;
	x=0;
	FOR(i,N) {
		if(A[i]==-1) {
			x++;
		}
		else if(uns) {
			int larger=bt(N)-bt(A[i]);
			(ret += larger*modpow(uns)%mo*x)%=mo;
			(ret += (uns-larger)*modpow(uns)%mo*(uns-x))%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}