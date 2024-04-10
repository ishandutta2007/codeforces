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
int cor[105],wro[105];
int main(){
	cin>>n>>m;
	REP(i,n) cin>>cor[i];
	REP(i,m) cin>>wro[i];

	sort(cor,cor+n);
	int res=max(cor[0]*2,cor[n-1]);
	sort(wro,wro+m);
	if(wro[0]<=res) res=-1;
	printf("%d\n",res);


	return 0;
}