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
int a[105];
int main(){
	cin>>n;
	REP(i,n) cin>>a[i+1];
	int res=0;
	for(int i=(n-1)/2;i>=2;--i){
		int tmp=max(a[i*2],a[i*2+1]);
		res+=tmp;
		a[i]-=min(a[i],tmp);
		a[i*2]-=min(a[i*2],tmp);
		a[i*2+1]-=min(a[i*2+1],tmp);
	}
	if((n-1)/2>=1){
		res+=max(a[1],max(a[2],a[3]));
		a[1]=a[2]=a[3]=0;
	}
	int fail=0;
	REP(i,n+1) if(a[i]) fail=1;
	if(fail) res=-1;
	cout<<res<<endl;
	return 0;
}