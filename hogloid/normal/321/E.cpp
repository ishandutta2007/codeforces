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

int n,k;
int infam[4005][4005];
int sum[4005][4005];
pi deq[805][4005];
int st[805],en[805];

int dp[4005][805];

int sum2[4005][4005];
int getsum(int a,int b){
	return (sum[b][b]+sum[a][a]-sum[b][a]-sum[a][b])/2;
}
int getcross(pi& a,pi& b){//(a.sc<b.sc)
	int gap=sum2[a.sc][b.sc];
	if(a.fr+gap>=b.fr) return b.sc;

	int lb=b.sc,ub=n+1;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(a.fr+sum2[a.sc][md]>=b.fr+sum2[b.sc][md]) ub=md;
		else lb=md;
	}
	return ub;
}

char tmp[1000005];

int main(){
	scanf("%d%d\n",&n,&k);

	REP(i,n) {
		gets(tmp);
		REP(j,n) infam[i][j]=tmp[j*2]-'0';
	}

	


	REP(i,n) REP(j,n) sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+infam[i][j];
	REP(i,n) REPN(j,n+1,i) sum2[i][j]=getsum(i,j);
	
	REP(i,n+1) REP(j,k+1) dp[i][j]=INF;
	dp[0][0]=0;
	
	deq[0][en[0]++]=mp(0,0);//(cost,starting_point)

	REPN(i,n+1,1) for(int j=k;j>=1;--j)if(st[j-1]<en[j-1]){
		while(st[j-1]+1<en[j-1] && getcross(deq[j-1][st[j-1]],deq[j-1][st[j-1]+1])<=i){
			++st[j-1];
		}
		pi top=deq[j-1][st[j-1]];
		dp[i][j]=top.fr+sum2[top.sc][i];//[top.sc...i)
		pi ins=mp(dp[i][j],i);
		while(st[j]+1<en[j]){
			int shift1;
			int shift2=getcross(deq[j][en[j]-1],ins);

			shift1=getcross(deq[j][en[j]-2],deq[j][en[j]-1]);

			if(shift1>=shift2){
				--en[j];
				continue;
			}
			break;
		}
		deq[j][en[j]++]=ins;
	}

	printf("%d\n",dp[n][k]);

	return 0;
}