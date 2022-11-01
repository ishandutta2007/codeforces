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

int cap[1000005];
int size[1000005];

lint able[35],init[35];
bool check(int m){
	REP(j,35) able[j]=init[j];
	
	int j=m-1;
	for(int i=34;i>=0;--i){
		while(j>=0 && size[j]==i){
			if(able[i]==0) return false;
			--able[i];
			--j;
		}
		if(i) able[i-1]+=able[i]*2;
	}

	return true;
}


int main(){
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&cap[i]);
	REP(i,m) scanf("%d",&size[i]);

	REP(i,n){
		REP(j,35) if(((lint)cap[i])>>j&1) ++init[j];
	}

	sort(size,size+m);
	sort(cap,cap+n);

	int lb=0,ub=m+1;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(check(md)) lb=md;
		else ub=md;
	}

	printf("%d\n",lb);

	return 0;
}