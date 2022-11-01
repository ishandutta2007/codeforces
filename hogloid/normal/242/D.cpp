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
vector<int> g[100005];
int n,m;
int a[100005];
int flag[100005];
int sum[100005];
void flip(int i,int c){
	sum[i]+=c;
	REP(j,g[i].size()) sum[g[i][j]]+=c;
}
int main(){
	cin>>n>>m;
	REP(i,m){
		int a,b;cin>>a>>b;--a;--b;
		g[a].pb(b);g[b].pb(a);
	}
	REP(i,n) cin>>a[i];
	REP(i,n) flag[i]=rand()%2;

	int ng=1;
	int nega[2]={1,-1};
	while(ng){
		memset(sum,0,sizeof(sum));
		REP(i,n) if(flag[i]){
			flip(i,1);
		}
		ng=0;
		REP(i,n) if(sum[i]==a[i]){
			int deg=g[i].size()+1;
			if(rand()%deg==0){
				flip(i,nega[flag[i]]);
				flag[i]^=1;
			}else{
				--deg;
				int j=rand()%deg;
				flip(g[i][j],nega[flag[g[i][j]]]);
				flag[g[i][j]]^=1;
			}
			ng=1;
		}
	}
	vector<int> ans;
	REP(i,n) if(flag[i]) ans.pb(i);
	printf("%d\n",(int)ans.size());
	REP(i,ans.size()) printf("%d%c",ans[i]+1,i==ans.size()-1?'\n':' ');

	

	return 0;
}