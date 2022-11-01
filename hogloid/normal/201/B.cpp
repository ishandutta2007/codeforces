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
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,m;
int c[1005][1005];
lint csum[1005],rsum[1005];
lint check(int a){
	lint res=0;
	REP(i,m) res+=csum[i]*(lint)(a*4-i*4-2)*(lint)(a*4-i*4-2);
	return res;
}
lint check2(int a){
	lint res=0;
	REP(i,n) res+=rsum[i]*(lint)(a*4-i*4-2)*(lint)(a*4-i*4-2);
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,m) scanf("%d",&c[i][j]);
	REP(i,n) REP(j,m){
		csum[j]+=c[i][j];
		rsum[i]+=c[i][j];
	}
	int lb=-1,ub=m+1;
	while(ub-lb>2){
		double lef=lb+(ub-lb)/3,ri=ub-(ub-lb)/3;
		if(check(lef)<=check(ri)){
			ub=ri;
		}else lb=lef;
	}
	int x=lb+1;

	lb=-1;ub=n+1;
	while(ub-lb>2){
		double lef=lb+(ub-lb)/3,ri=ub-(ub-lb)/3;
		if(check2(lef)<=check2(ri)){
			ub=ri;
		}else lb=lef;
	}
	int y=lb+1;
	cout<<check(x)+check2(y)<<endl;
	printf("%d %d\n",y,x);
	return 0;
}