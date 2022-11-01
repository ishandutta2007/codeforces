#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
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
typedef long double ld;
typedef pair<int,int> pi;
int h,w;
int buf[505][505];
int memo[3][505][505];
int colsum[505][505],rowsum[505][505];
int main(){
	scanf("%d%d",&h,&w);
	REP(i,h) REP(j,w) scanf("%d",&buf[i][j]);
	REP(i,h){
		rowsum[i][0]=0;
		REP(j,w) rowsum[i][j+1]=rowsum[i][j]+buf[i][j];
	}
	REP(i,w){
		colsum[0][i]=0;
		REP(j,h) colsum[j+1][i]=colsum[j][i]+buf[j][i];
	}
	int res=-INF;
	int a=0,b=1,c=2;
	memset(memo,0,sizeof(memo));
	for(int len=1;len<=min(h,w);len+=2){
		REP(i,h-len+1) REP(j,w-len+1){
			int tmp;
			if(len==1) tmp=buf[i][j];
			else tmp=rowsum[i][j+len-1]-rowsum[i][j]
					+colsum[i+len-1][j+len-1]-colsum[i][j+len-1]
					+rowsum[i+len-1][j+len]-rowsum[i+len-1][j+1]
					+colsum[i+len][j]-colsum[i+2][j]
					+memo[a][i+2][j+2]+(len==3?0:buf[i+2][j+1]);
			if(len!=1) res=max(res,tmp);
			memo[c][i][j]=tmp;
		}
		int t=a;
		a=b;
		b=c;
		c=t;
	}
	printf("%d\n",res);

			
	return 0;
}