#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define EPS (1e-8)
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
int n;
int val[20005];
int get(int ver){
	if(ver<3) return -INF;
	int jump=n/ver,res=-INF;
	REP(i,jump){
		int tmp=0;
		for(int j=i;j<n;j+=jump) tmp+=val[j];
		res=max(res,tmp);
	}
	return res;
}
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&val[i]);
	int res=-INF;
	for(int i=1;i*i<=n;++i) if(n%i==0){
		res=max(res,max(get(i),get(n/i)));
	}
	printf("%d\n",res);
	return 0;
}