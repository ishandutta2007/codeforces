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
int solve(){
	int x,y;scanf("%d%d",&x,&y);

	int deg=max(abs(x),abs(y));

	if(x==deg && y==-deg+1) return 4*deg;
	if(x==deg && y!=-deg) return 4*deg+1;
	if(y==deg) return 4*deg+2;
	if(x==-deg) return 4*deg+3;
	if(y==-deg) return 4*deg+4;
	prl;
	while(1){}
}
int main(){
	printf("%d\n",max(0,solve()-4));

	return 0;
}