#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<numeric>
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
//O(N) algorithm
int n;
int ar[105];
int sum[105],latermin[105];
int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	REP(i,n) sum[i+1]=sum[i]+(ar[i]==1?1:-1);
	
	latermin[n+1]=INF;
	for(int i=n;i>=0;--i) latermin[i]=min(latermin[i+1],sum[i]);	
	
	int tot=accumulate(ar,ar+n,0);
	int res=0;
	REP(i,n){
		res=max(res,tot-(latermin[i+1]-sum[i]));
	}
	cout<<res<<endl;


	return 0;
}