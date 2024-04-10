#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
string s[2005];
int n,K;
int lcp[2005];
int prof[2005][2005];
struct segtree{
	pi val[10000];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=mp(INF,INF);
	}
	void set(int k,int a){
		val[k+n-1]=mp(a,k);
		k+=n-1;
		while(k>0){
			k=(k-1)/2;
			val[k]=min(val[k*2+1],val[k*2+2]);
		}
	}
	pi query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return mp(INF,INF);
		int md=(l+r)>>1;
		return min(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};
segtree seg;
int dp[105][105][105];
int rec(int s,int e,int k){
	k=min(k,e-s);
	if(e-s==1) return 0;
	if(dp[s][e][k]!=-1) return dp[s][e][k];
	pi mini=seg.query(s,e-1,0,0,seg.n);
	REP(i,k+1) dp[s][e][k]=max(dp[s][e][k],rec(s,mini.sc+1,i)+rec(mini.sc+1,e,k-i)+i*(k-i)*mini.fr);
	return dp[s][e][k];
}

int main(){
	
	scanf("%d%d",&n,&K);
	REP(i,n) cin>>s[i];
	sort(s,s+n);
	seg.init(n);
	REP(i,n-1){
		int& t=lcp[i];
		for(t=0;t<s[i].size() &&t<s[i+1].size() && s[i][t]==s[i+1][t];++t);
		seg.set(i,t);
	}
	REP(i,n) prof[i][i]=0;
	for(int len=1;len<=n-1;++len) REP(i,n-len) {
		int j=i+len;
		pi mini=seg.query(i,j,0,0,seg.n);
		prof[i][j]=prof[i][mini.sc]+prof[mini.sc+1][j]+(mini.sc-i+1)*(j-mini.sc)*mini.fr;
	}
	memset(dp,-1,sizeof(dp));

	printf("%d\n",rec(0,n,K));
	return 0;
}