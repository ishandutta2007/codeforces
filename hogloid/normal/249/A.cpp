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

int main(){
	double y1,y2,yw,xb,yb,r;
	cin>>y1>>y2>>yw>>xb>>yb>>r;
	yw-=r;
	double y3=yw+(yw-y2),y4=yw+(yw-y1)-r;
	double dst=abs(xb*y3-y4*xb)/sqrt(xb*xb+(y4-yb)*(y4-yb));
	dump(dst);
	if(dst<=r) puts("-1");
	else{
		double x2=xb/(y4-yb)*(y4-yw);
		printf("%.10f\n",x2);
	}
	return 0;
}