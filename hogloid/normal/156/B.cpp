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
int n,m;
int val[2][100005];
int tip[100005],able[100005];
int main(){
	scanf("%d%d",&n,&m);
	REP(i,n){
		int a;scanf("%d",&a);
		tip[i]=a;
		if(a>0){
			--a;
			val[0][a]++;
		}else{
			a=-a;--a;
			val[1][a]++;
		}
	}
	int sum2=0;
	REP(i,n) sum2+=val[1][i];
	
	int num=0;
	REP(i,n){
		int kagami=sum2-val[1][i]+val[0][i];
		if(kagami==m){
			able[i]=1;
			++num;
		}
	}
	REP(i,n){
		if(tip[i]>0){
			if(able[tip[i]-1]==0) puts("Lie");
			else if(num==1) puts("Truth");
			else puts("Not defined");
		}else{
			if(able[-tip[i]-1]==1 && num==1) puts("Lie");
			else if(able[-tip[i]-1]==1) puts("Not defined");
			else puts("Truth");
		}
	}

	return 0;
}