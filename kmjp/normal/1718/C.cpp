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

int T,N,Q;
int A[202020];
ll tsum[1<<20];
int start[202020],num[202020];

template<class V> class SegTree_d {
public:
	int NV,level;
	V* val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	void init(int level,V* v) {
		this->level=level;
		NV=1<<level;
		val=v;
		int i;
		FOR(i,NV*2) val[i]=def;
	}
	V getval(int x,int y,int l=0,int r=-1,int k=1) { // x<=i<y
		if(r==-1) r=NV;
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	ll update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
		return val[entry];
	}
};
SegTree_d<ll> st[202020];
ll val[1<<21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&Q);
		FOR(i,N) scanf("%d",&A[i]);
		vector<int> C;
		int s=0;
		for(i=1;i<N;i++) if(N%i==0) {
			C.push_back(i);
			x=0;
			while((1<<x)<i) x++;
			st[i].init(x,(ll*)&val[s]);
			s+=2<<x;
		}
			
		ll ret=0;
		int id=0;
		
		FORR(c,C) {
			start[c]=id;
			FOR(i,c) {
				ll sum=0;
				for(j=i;j<N;j+=c) sum+=A[j];
				tsum[id]=sum*c;
				ret=max(ret,tsum[id]);
				st[c].update(i,tsum[id]);
				id++;
			}
		}
		cout<<ret<<endl;
		while(Q--) {
			scanf("%d%d",&x,&y);
			x--;
			ret=0;
			FORR(c,C) {
				i=x%c;
				tsum[start[c]+i]+=1LL*(y-A[x])*c;
				ret=max(ret,st[c].update(i,tsum[start[c]+i]));
			}
			A[x]=y;
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