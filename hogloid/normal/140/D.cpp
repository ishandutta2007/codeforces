#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int a[105];
int main(){
	int n;scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);
	int m=0,sum=10,penal=0;
	while(m<n && sum+a[m]<=720){
		sum+=a[m];
		penal+=max(0,sum-360);
		++m;
	}
	printf("%d %d\n",m,penal);

	return 0;
}