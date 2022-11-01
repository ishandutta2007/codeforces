#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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
int n,m;
int g[105][105];
int cost[105];
long double way[105];
int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a][b]=g[b][a]=1;
	}
	long double res=1;
	int length;
	long double all;
	for(int i=0;i<n-1;++i){
		memset(cost,-1,sizeof(cost));
		REP(j,n) way[j]=0;
		cost[0]=0;
		queue<int>q;q.push(0);
		way[0]=1;
		while(!q.empty()){
			int cur=q.front();q.pop();
			REP(j,n) if(g[cur][j] && j!=i){
				if(cost[j]==-1){
					cost[j]=cost[cur]+1;
					q.push(j);
					way[j]=way[cur];
				}else if(cost[j]==cost[cur]+1){
					way[j]+=way[cur];
				}
			}
		}
		if(i==0){
			length=cost[n-1];
			all=way[n-1];
		}else{
			if(length!=cost[n-1]){
				res=2;break;
			}
			long double tmp=(all-way[n-1])/all;
			res=max(res,tmp*2);
		}
	}
	printf("%.10f\n",(double)res);
	return 0;
}