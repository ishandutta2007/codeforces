#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
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
double PI= acos(-1.0);
double dx[10],dy[10];
int main(){
	double ang=0,cx=0,cy=0;
	REP(i,5){
		dx[i]=cx;dy[i]=cy;
		cx+=cos(ang)*10;cy+=sin(ang)*10;
		ang+=72.0/360.0*2*PI;
	}
	double difx=(dx[2]-dx[1])*2+dx[1];
	rotate(dx,dx+4,dx+5);
	rotate(dy,dy+4,dy+5);
	int n;scanf("%d",&n);
	printf("%d\n",n*5-n+1);
	REP(j,n){
		if(j==0){
			REP(i,5) printf("%.11f %.11f\n",dx[i],dy[i]);
		}else REP(i,4) printf("%.11f %.11f\n",dx[i+1]+difx*j,dy[i+1]);
	}
	REP(i,n){
		if(i==0) REP(j,5) printf("%d%c",j+1,j==4?'\n':' ');
		else{
			printf("%d",i*4);
			REP(j,4) printf(" %d",j+2+4*i);
			putchar('\n');
		}
	}
	printf("%d",1);
	REP(i,n) printf(" %d",i*4+4);
	for(int i=n-1;i>=0;--i){
		if(i==0) printf(" 2 5 3 1\n");
		else printf(" %d %d %d %d",i*4-2+4,i*4+1+4,i*4-1+4,i*4);
	}


	return 0;
}