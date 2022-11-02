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
int n,k;
int score[55];
int main(){
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&score[i]);
	if(score[k-1]>0){
		int i=k-1;
		while(i<n && score[i]==score[k-1]) ++i;
		printf("%d\n",i);
	}else{
		int res=0;
		REP(i,n) if(score[i]>0) ++res;
		printf("%d\n",res);
	}
	return 0;
}