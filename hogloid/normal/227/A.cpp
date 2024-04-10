#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
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
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
const double PI=acos(-1.0);
double mabs(double a){
	if(a<0) return -a;
	return a;
}
int main(){
	pi p[3];
	REP(i,3) cin>>p[i].fr>>p[i].sc;
	
	double a1=atan2((double)p[1].sc-p[0].sc,(double)p[1].fr-p[0].fr),
		a2=atan2((double)p[2].sc-p[1].sc,(double)p[2].fr-p[1].fr);
	if(abs(a1-a2)<1e-5) puts("TOWARDS");
	else if(min(mabs(a1+PI/2-PI*2-a2),mabs(a1+PI/2-a2))<1e-5) puts("LEFT");
	else puts("RIGHT");


	return 0;
}