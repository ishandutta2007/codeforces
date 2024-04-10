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
int n;
int g[505][505];

int perm[505],done[505];

lint ans[505];
int main(){
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&g[i][j]);
	REP(i,n) scanf("%d",&perm[i]),--perm[i];

	reverse(perm,perm+n);
	
	lint sum=0;
	REP(hoge,n){
		int i=perm[hoge];
		REP(j,n) if(done[j]) sum+=g[i][j],sum+=g[j][i];
		
		done[i]=1;
		REP(j,n) if(done[j]) REP(k,n) if(done[k]){
			if(g[i][j]>g[i][k]+g[k][j]){
				sum-=g[i][j]-g[i][k]-g[k][j];
				g[i][j]=g[i][k]+g[k][j];
			}
			if(g[j][i]>g[j][k]+g[k][i]){
				sum-=g[j][i]-g[j][k]-g[k][i];
				g[j][i]=g[j][k]+g[k][i];
			}
		}
		REP(j,n) if(done[j]) REP(k,n) if(done[k]){
			if(g[j][k]>g[j][i]+g[i][k]){
				sum-=g[j][k]-g[j][i]-g[i][k];
				g[j][k]=g[j][i]+g[i][k];
			}
		}
		ans[hoge]=sum;
	}
	reverse(ans,ans+n);
	REP(i,n) cout<<ans[i]<<endl;

	return 0;
}