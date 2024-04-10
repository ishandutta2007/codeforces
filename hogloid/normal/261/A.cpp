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
int m,n;
int q[100005],a[100005];
int main(){
	cin>>m;
	REP(i,m) cin>>q[i];
	int mini=*min_element(q,q+m);

	cin>>n;
	REP(i,n) cin>>a[i];

	sort(a,a+n);

	int res=0;
	
	for(int i=n-1;i>=0;i-=mini+2){
		REPN(j,i+1,max(0,i-mini+1)) res+=a[j];
	}
	cout<<res<<endl;

	return 0;
}