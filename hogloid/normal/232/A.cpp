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
int g[105][105];
void solve(int k){
	memset(g,0,sizeof(g));
	int def;
	REP(i,105) if(i*(i-1)*(i-2)/6<=k){
		def=i;
	}
	REP(i,def) REP(j,def) if(i!=j) g[i][j]=1;
	k-=def*(def-1)*(def-2)/6;
	int size=def;
	while(k>0){
		int add=0;
		REP(i,def+1){
			if(i*(i-1)/2<=k) add=i;
		}
		REP(i,add) g[size][i]=g[i][size]=1;
		k-=add*(add-1)/2;
		++size;
	}
	printf("%d\n",size);
	REP(i,size){
		REP(j,size) printf("%d",g[i][j]);
		putchar('\n');
	}
}
int main(){
	int k;
	cin>>k;
	solve(k);

	return 0;
}