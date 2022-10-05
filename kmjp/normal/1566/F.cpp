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


int T;
int N,M;
ll A[202020];
pair<ll,ll> P[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1LL<<60;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v,bool ow=0) {
		entry += NV;
		if(ow) {
			val[entry]=v;
		}
		else {
			val[entry]=comp(v,val[entry]); //
		}
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<ll,1<<20> st1,st2;
ll dp[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		FOR(i,N) {
			scanf("%d",&x);
			A[i]=x;
		}
		A[N]=-1LL<<41;
		A[N+1]=1LL<<40;
		N+=2;
		
		
		FOR(i,M) {
			scanf("%d%d",&x,&y);
			P[i]={x,y};
		}
		P[M].first=P[M].second=-1LL<<40;
		P[M+1].first=P[M+1].second=1LL<<41;
		M+=2;
		sort(A,A+N);
		sort(P,P+M);
		
		
		vector<pair<ll,ll>> V;
		FOR(i,M) {
			if(V.size()&&V.back().first==P[i].first) continue;
			x=lower_bound(A,A+N,P[i].first)-A;
			if(x<N&&A[x]<=P[i].second) continue;
			while(V.size()&&V.back().second>=P[i].second) V.pop_back();
			V.push_back(P[i]);
		}
		
		if(V.size()==2) {
			cout<<0<<endl;
			continue;
		}
		
		FOR(i,N+M+5) st1.update(i,1LL<<60,1),st2.update(i,1LL<<60,1),dp[i]=1LL<<60;
		st1.update(0,-V[1].second,1);
		st2.update(0,-2*V[1].second,1);
		dp[0]=0;
		
		M=V.size();
		for(i=1;i<N-1;i++) {
			int nex=lower_bound(ALL(V),make_pair(A[i],A[i]))-V.begin();
			int pre=lower_bound(ALL(V),make_pair(A[i-1],A[i-1]))-V.begin();
			
			//
			ll now=st1.getval(nex-1,nex)+V[nex].second;
			now=min(now,st2.getval(0,nex-1)+2*A[i]);
			for(j=nex;V[j].first<A[i+1];j++) {
				chmin(dp[j],now+(V[j].first-A[i]));
				st1.update(j,dp[j]-V[j+1].second);
				st2.update(j,dp[j]-2*V[j+1].second);
			}
			//
			now=st1.getval(nex-1,nex)+V[nex].second;
			now=min(now,st1.getval(0,nex-1)+1*A[i]);
			for(j=nex;V[j].first<A[i+1];j++) {
				chmin(dp[j],now+2*(V[j].first-A[i]));
				st1.update(j,dp[j]-V[j+1].second);
				st2.update(j,dp[j]-2*V[j+1].second);
			}
			now=st1.getval(0,nex-1)+A[i];
			chmin(dp[nex-1],now);
			st1.update(nex-1,now-V[nex].second);
			st2.update(nex-1,now-2*V[nex].second);
			
		}
		
		cout<<dp[M-2]<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}