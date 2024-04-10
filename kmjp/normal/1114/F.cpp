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
ll cand[303];

const int prime_max = 301;
int NP,prime[100],divp[prime_max];
ll mo=1000000007;
ll re[65];

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}


template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){int i;
		FOR(i,1<<ME) bit[0][i]=bit[1][i]=1;
	};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) (bit[0][entry-1]*=val0)%=mo, (bit[1][entry-1]*=val1)%=mo, entry += entry & -entry;
	}
	V total(int entry) {
		int e=entry++;
		V v0=1,v1=1;
		while(entry>0) (v0*=bit[0][entry-1])%=mo, (v1*=bit[1][entry-1])%=mo, entry -= entry & -entry;
		return modpow(v0,e)*v1%mo;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,modpow(modpow(val,L-1)));
		update(R+1,modpow(val),modpow(val,R));
	}
};
BIT_r<ll,19> bt;

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return ma[k];
		return val[k] | getval(x,y,l,(l+r)/2,k*2)|getval(x,y,(l+r)/2,r,k*2+1);
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]|=v;
			ma[k]|=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]|ma[k*2]|ma[k*2+1];
		}
	}
};
SegTree_3<ll,1<<19> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	scanf("%d%d",&N,&Q);
	for(i=1;i<=300;i++) {
		x=i;
		FOR(j,NP) {
			if(x%prime[j]==0) cand[i] |= 1LL<<j;
			while(x%prime[j]==0) x/=prime[j];
		}
	}
	FOR(i,NP) re[i]=(prime[i]-1)*modpow(prime[i])%mo;
	FOR(i,N) {
		scanf("%d",&x);
		bt.add(i+1,i+1,x);
		st.update(i+1,i+2,cand[x]);
	}
	
	
	while(Q--) {
		char buf[10];
		int L,R;
		scanf("%s%d%d",buf,&L,&R);
		R++;
		if(buf[0]=='M') {
			scanf("%d",&x);
			
			bt.add(L,R-1,x);
			st.update(L,R,cand[x]);
		}
		else {
			ll v=bt.total(R-1)*modpow(bt.total(L-1))%mo;
			ll mask=st.getval(L,R);
			FOR(i,NP) if(mask&(1LL<<i)) {
				v=v*re[i]%mo;
			}
			cout<<v<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}