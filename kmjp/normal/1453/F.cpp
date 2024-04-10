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
int N;
int A[3030];
int can[3030],cost[3030];
int dp[3030][3030];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	void reinit(){FORR(v,val) v=def;}
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
SegTree_1<int,1<<12> st[3030];
 
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		
		cin>>N;
		FOR(i,N) {
			cin>>A[i+1];
			cost[i+1]=0;
		}
		
		
		can[N]=1;
		for(i=N-1;i>=1;i--) {
			can[i]=0;
			
			for(x=i+1;x<=i+A[i];x++) can[i]|=can[x];
			if(can[i]==0) A[i]=0;
		}
		
		
		dp[N][N]=0;
		for(i=N-1;i>=1;i--) if(can[i]) {
			int del=0;
			st[i].reinit();
			for(x=i+1;x<=i+A[i];x++) {
				if(x==N) {
					dp[i][x]=cost[x];
				}
				else if(can[x]==0||i+A[i]>=x+A[x]) {
					dp[i][x]=1<<30;
				}
				else {
					dp[i][x]=st[x].getval(i+A[i]+1,x+A[x]+1)+cost[x];
				}
				cost[x]++;
				//cout<<i<<x<<" "<<dp[i][x]<<endl;
				st[i].update(x,dp[i][x]);
			}
		}
		
		int ret=1<<20;
		for(x=2;x<=1+A[1];x++) ret=min(ret,dp[1][x]);
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}