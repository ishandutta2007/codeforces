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
int n;
double p[100005];
double get(int i){
	if(i==-1) return 0;
	return p[i];
}
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%lf",&p[i]);
	double res=0,prev=0;
	REP(i,n){
		prev=prev*p[i]+p[i]*get(i-1)*2;
		prev+=p[i]*(1-get(i-1));
		res+=prev;
	}
	printf("%.10f\n",res);
	return 0;
}