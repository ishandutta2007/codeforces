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
int a,b,k;
int table[1000005],prime[100000];
int sum[1000005];
int main(){
	cin>>a>>b>>k;
	++b;
	REP(i,1000005) table[i]=1;
	table[0]=table[1]=0;
	for(int i=2;i*i<1000005;++i) if(table[i]){
		for(int j=i*i;j<1000005;j+=i) table[j]=0;
	}
	int m=0;
	REP(i,1000005) if(table[i]) prime[m++]=i;
	int lb=0,ub=b-a+1;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		for(int i=1000000;i>=0;--i){
			sum[i]=sum[i+1]+table[i]-(i+md<=1000000?table[i+md]:0);
		}
		int fail=0;
		for(int i=a;i<=b-md;++i) if(sum[i]<k){
			fail=1;break;
		}
		if(fail) lb=md;
		else ub=md;
	}
	if(ub==b-a+1) ub=-1;
	cout<<ub<<endl;
	return 0;
}