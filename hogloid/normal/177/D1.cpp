#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int n,m,c;
int seq[100005],add[100005],sum[100005];
int main(){
	scanf("%d%d%d",&n,&m,&c);
	REP(i,n) scanf("%d",&seq[i]);
	REP(i,m) scanf("%d",&add[i]);
	REP(i,m){
		sum[i]+=add[i];
		sum[i+n-m+1]-=add[i];
	}
	REP(i,n) sum[i+1]+=sum[i];
	REP(i,n) printf("%d%c",(seq[i]+sum[i])%c,i==n-1?'\n':' ');
	return 0;
}