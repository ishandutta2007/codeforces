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
pi ans[505];
int main(){
	ans[n++]=mp(0,1000000);
	REP(i,400) ans[n++]=mp(45000+(401+(402-i))*i,400-i);
	ans[n]=mp(ans[n-1].fr+45000,1000000);
	n++;
	printf("%d\n",n);
	REP(i,n) printf("%d %d\n",ans[i].fr,ans[i].sc);

	return 0;
}