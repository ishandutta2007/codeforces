#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int hp1,t1,l1,r1,p1,
	hp2,t2,l2,r2,p2;
double dp[220][220][70];
double sumi[220][220][70],sumj[220][220][70];
double ave1[70],ave2[70];
int zip[70];
int main(){
	scanf("%d%d%d%d%d%d%d%d%d%d",&hp1,&t1,&l1,&r1,&p1,&hp2,&t2,&l2,&r2,&p2);
	if(p1==100){
		printf("%.10f\n",0.0);
		return 0;
	}
	if(p2==100){
		printf("%.10f\n",1.0);
		return 0;
	}
	double P1=p1/100.0,P2=p2/100.0;
	int cnt=0,lcm=t1*t2/__gcd(t1,t2);
	REP(i,lcm){
		if(i%t1==0) zip[cnt++]=1;
		if(i%t2==0) zip[cnt++]=2;
	}
	REP(i,220) REP(j,220) REP(k,70) dp[i][j][k]=sumi[i][j][k]=sumj[i][j][k]=0;
	REP(i,hp1) REP(j,hp2){
		REP(k,cnt){
			ave1[k]=ave2[k]=0;
			int lb=j-r1,ub=j-l1+1;
			if(lb<0) ave1[k]+=-lb,lb=0;
			if(ub<0) ave1[k]+=ub,ub=0;
			ave1[k]+=sumj[i][ub][(k+1)%cnt]-sumj[i][lb][(k+1)%cnt];
			ave1[k]/=r1-l1+1;
			
			lb=i-r2;ub=i-l2+1;
			lb=max(lb,0);
			ub=max(ub,0);
			ave2[k]+=sumi[ub][j][(k+1)%cnt]-sumi[lb][j][(k+1)%cnt];
			ave2[k]/=r2-l2+1;
		}

		REP(k,cnt){
			double cur=1.0;
			REP(l,cnt){
				int ev=zip[(k+l)%cnt];
				if(ev==1){
					dp[i][j][k]+=ave1[(k+l)%cnt]*cur*(1-P1);
					cur*=P1;
				}else{
					dp[i][j][k]+=ave2[(k+l)%cnt]*cur*(1-P2);
					cur*=P2;
				}
			}
			dp[i][j][k]/=1.0-cur;
			sumi[i+1][j][k]=sumi[i][j][k]+dp[i][j][k];
			sumj[i][j+1][k]=sumj[i][j][k]+dp[i][j][k];
		}
	}
	printf("%.10f\n",dp[hp1-1][hp2-1][0]);

	return 0;
}