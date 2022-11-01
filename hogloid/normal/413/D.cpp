#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n,k;
int ar[2005];

const lint mod=1000000007;
template<class T> void chadd(T& a,const T& b) { a+=b; if(a>=mod) a-=mod;}
lint dp[2][1<<12];
int main(){
	cin>>n>>k;
	REP(i,n){
		cin>>ar[i];
		if(ar[i]!=0)ar[i]/=2;
	}
	
	int cur=0,nxt=1;
	dp[cur][0]=1;

	--k;
	REP(i,n){
		REP(j,1<<12) if(dp[cur][j]){
			for(int t=1;t<=2;t+=1) if(ar[i]==0 || ar[i]==t){
				int nbit=j+t;
				if(t==2 && (j&1) && j<(1<<k)) nbit=t;
				chadd(dp[nxt][nbit],dp[cur][j]);
			}
		}
		swap(cur,nxt);
		memset(dp[nxt],0,sizeof(dp[nxt]));
	}
	lint res=0;
	REP(i,1<<12) if(i>=(1<<k)){
		chadd(res,dp[cur][i]);
	}

	cout<<res<<endl;

	return 0;
}