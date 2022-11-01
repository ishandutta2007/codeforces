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
int m;
double r;
double sq2=sqrt(2.0);
double calc(int n){
	if(n<=0) return 0;
	return sq2*2*n*r+n*(double)(n+1)*r;
}
int main(){
	cin>>m>>r;

	double ave=0;
	REP(i,m){
		ave+=2*r;
		if(i>0) ave+=2*r+sq2*r;
		if(i<m-1) ave+=2*r+sq2*r;


		ave+=calc(i-1);
		ave+=calc(m-i-2);
	}
	ave/=m*(lint)m;
	printf("%.10f\n",ave);

	return 0;
}