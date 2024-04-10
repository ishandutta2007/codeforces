#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
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

int dp[405][405];
int n,v,m;
int income[405];


int csum[405][405];
pi cost[405][405];
int cnt[405];

pi back[405][405];

vector<int> ans[405];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>v;
	REP(i,n) cin>>income[i];

	cin>>m;
	REP(i,m){
		int l,r,f;cin>>l>>r>>f;

		--l;
		REPN(j,r,l) cost[j][cnt[j]++]=mp(f,i);
	}
	REP(i,n) sort(cost[i],cost[i]+cnt[i]);
	REP(i,n){
		REP(j,cnt[i]) csum[i][j+1]=csum[i][j]+cost[i][j].fr;
	}

	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;

	REP(i,n) REP(j,405) if(dp[i][j]!=-1){
		int nj;
		REP(k,cnt[i]+1){
			nj=min(income[i],income[i]+j-csum[i][k]-v);
			if(nj<0) break;
			if(dp[i+1][nj]<dp[i][j]+k){
				dp[i+1][nj]=dp[i][j]+k;
				back[i+1][nj]=mp(j,k);
			}
		}
	}

	int res=0;
	pi cur;
	REP(j,405) if(res<dp[n][j]){
		res=dp[n][j];
		cur=back[n][j];
	}

	printf("%d\n",res);

	for(int i=n-1;i>=0;--i){
		REP(j,cur.sc) ans[i].pb(cost[i][j].sc+1);
		cur=back[i][cur.fr];
	}

	REP(i,n){
		printf("%d",(int)ans[i].size());
		REP(j,ans[i].size()) printf(" %d",ans[i][j]);
		putchar('\n');
	}

	return 0;
}