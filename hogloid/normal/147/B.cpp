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
int n,m;
int g[305][305];

int tmp[40][305][305];
void merge(int a,int b,int c){
	REP(i,n) REP(j,n) tmp[c][i][j]=-INF;
	REP(i,n) REP(j,n) if(tmp[a][j][i]>-INF) REP(k,n) tmp[c][j][k]=max(tmp[c][j][k],tmp[a][j][i]+tmp[b][i][k]);
}
bool check(int k){
	REP(i,n) REP(j,n) tmp[0][i][j]=g[i][j];
	REP(i,n) REP(j,n) tmp[1][i][j]=-INF;
	REP(i,n) tmp[1][i][i]=0;

	int cnt=2,a=0,res=1;
	while(k){
		if(k&1){
			merge(res,a,cnt++);
			res=cnt-1;
		}
		merge(a,a,cnt++);
		a=cnt-1;
		k>>=1;
	}
	REP(i,n) if(tmp[res][i][i]>0) return true;
	return false;
}

int main(){
	cin>>n>>m;
	REP(i,n) REP(j,n) g[i][j]=-INF;
	REP(i,m){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);--a;--b;
		g[a][b]=c;
		g[b][a]=d;
	}
	REP(i,n) g[i][i]=0;
	
	REP(i,n) REP(j,n) tmp[20][i][j]=-INF;
	REP(i,n) tmp[20][i][i]=0;

	memcpy(tmp[0],g,sizeof(g));

	int m,p;
	for(m=1,p=1;p<=n;p*=2,++m) merge(m-1,m-1,m);
	int res=INF;
	int cur=20,sum=0;
	for(int i=m-1;i>=0;--i){
		merge(cur,i,cur+1);

		int suc=0;
		REP(j,n) if(tmp[cur+1][j][j]>0) suc=1;
		if(!suc) cur=cur+1,sum+=(1<<i);
		else res=sum+(1<<i);
	}
	
	if(res==INF) res=0;
	printf("%d\n",res);

	return 0;
}