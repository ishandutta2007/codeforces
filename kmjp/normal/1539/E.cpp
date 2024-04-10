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

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=0;
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
};

template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	static V const def=1LL<<30;
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
};

SegTree_ma<int,1<<18> LA,RA;
SegTree_mi<int,1<<18> LB,RB;

int N,M;
int K[191919];
int ma[2][101010];

int dp[2][101010];
int from[2][101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>K[i+1];
		cin>>x>>y;
		LA.update(i+1,x);
		LB.update(i+1,y);
		cin>>x>>y;
		RA.update(i+1,x);
		RB.update(i+1,y);
	}
	FOR(i,N+1) {
		k=K[i];
		x=y=i-1;
		for(j=19;j>=0;j--) {
			if(x+(1<<j)<=N) if(LA.getval(i,x+(1<<j)+1)<=K[i]&&LB.getval(i,x+(1<<j)+1)>=K[i]) x+=1<<j;
			if(y+(1<<j)<=N) if(RA.getval(i,y+(1<<j)+1)<=K[i]&&RB.getval(i,y+(1<<j)+1)>=K[i]) y+=1<<j;
		}
		ma[0][i]=x;
		ma[1][i]=y;
	}
	MINUS(dp);
	dp[0][0]=ma[1][0];
	dp[1][0]=ma[0][0];
	for(i=1;i<=N;i++) {
		if(ma[0][i]>=i) { 
			if(dp[0][i-1]>=i&&dp[0][i-1]>dp[0][i]) { // 0->0
				dp[0][i]=dp[0][i-1];
				from[0][i]=0;
			}
			if(dp[1][i-1]>=i-1&&ma[1][i-1]>=i&&ma[1][i-1]>dp[0][i]) { // 1->0
				dp[0][i]=ma[1][i-1];
				from[0][i]=1;
			}
		}
		if(ma[1][i]>=i) { 
			if(dp[1][i-1]>=i&&dp[1][i-1]>dp[1][i]) { // 1->1
				dp[1][i]=dp[1][i-1];
				from[1][i]=1;
			}
			if(dp[0][i-1]>=i-1&&ma[0][i-1]>=i&&ma[0][i-1]>dp[1][i]) { // 0->1
				dp[1][i]=ma[0][i-1];
				from[1][i]=0;
			}
		}
	}
	int cur=-1;
	if(dp[0][N]>=N) cur=0;
	if(dp[1][N]>=N) cur=1;
	
	if(cur==-1) {
		cout<<"No"<<endl;
	}
	else {
		vector<int> R;
		while(N) {
			R.push_back(cur);
			cur=from[cur][N];
			N--;
		}
		
		cout<<"Yes"<<endl;
		reverse(ALL(R));
		FORR(v,R) cout<<v<<" ";
		cout<<endl;
	}
	
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}