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
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
static const lint INF =1e18; 
int n,k;
lint ar[200005],sum[200005];
pair<lint,lint> latmax[200005];
int main(){
	cin>>n>>k;
	REP(i,n) cin>>ar[i];
	
	REP(i,n) sum[i+1]=sum[i]+ar[i];
	
	lint res=-INF;
	int a,b;
	REP(i,n+2) latmax[i]=mp(-INF,0);
	for(int i=n-k;i>=0;--i){
		latmax[i]=max(latmax[i+1],mp(sum[i+k]-sum[i],-(lint)i));
		
		if(res<=latmax[i+k].fr+sum[i+k]-sum[i]){
			res=latmax[i+k].fr+sum[i+k]-sum[i];
			a=-i;b=latmax[i+k].sc;
		}
	}
	printf("%d %d\n",-a+1,-b+1);



	return 0;
}