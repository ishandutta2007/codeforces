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

template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_mi(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
	void set(int entry, V v) {
		entry += NV;
		val[entry]=v; //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
	void set(int entry, V v) {
		entry += NV;
		val[entry]=v; //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int T,N;
int P[303030];
int dp[303030];
int pre[303030];
SegTree_mi<int,1<<20> smi;
SegTree_ma<int,1<<20> sma;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		sma.set(0,0);
		smi.set(0,0);
		FOR(i,N) {
			cin>>P[i+1];
			if(P[i+1]) {
				sma.set(i+1,i+1+P[i+1]);
			}
			else {
				sma.set(i+1,-1);
			}
			smi.set(i+1,1<<20);
		}
		dp[0]=0;
		for(i=1;i<=N;i++) {
			dp[i]=-1<<20;
			//
			x=smi.getval(max(0,i-P[i]-1),N+1);
			if(x<1<<20) {
				y=max(sma.getval(x+1,i),i-1);
				if(y>dp[i]) {
					dp[i]=y;
					pre[i]=x;
				}
			}
			
			if(dp[i-1]>=i&&dp[i]<max(dp[i-1],i+P[i])) {
				dp[i]=max(dp[i-1],i+P[i]);
				pre[i]=-1;
			}
			if(dp[i-1]>=dp[i]) {
				dp[i]=dp[i-1];
				pre[i]=-1;
			}
			if(dp[i]>N) dp[i]=N;
			smi.update(dp[i],i);
		}
		if(dp[N]!=N) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
			string S;
			int cur=N;
			while(cur) {
				if(pre[cur]==-1) {
					cur--;
					S.push_back('R');
				}
				else {
					x=pre[cur];
					cur--;
					S.push_back('L');
					while(cur>x) cur--,S.push_back('R');
				}
			}
			reverse(ALL(S));
			cout<<S<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}