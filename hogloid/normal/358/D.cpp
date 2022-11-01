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
int a[3005],b[3005],c[3005];
int main(){
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>b[i];
	REP(i,n) cin>>c[i];
	
	int sum1=b[0],sum2=a[0];
	//sum1...assume next is full
	//sum2...assume next isn't full
	REPN(i,n,1){
		int tmp1,tmp2;
		tmp1=max(sum1+b[i],sum2+c[i]);
		tmp2=max(sum1+a[i],sum2+b[i]);

		sum1=tmp1;sum2=tmp2;
	}
	printf("%d\n",sum2);


	return 0;
}