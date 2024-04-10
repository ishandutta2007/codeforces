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
static const int INF =1050000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,x;
lint a[100005];
lint latermin[100005],evermin[100005];
int main(){
	cin>>n>>x;
	REP(i,n) cin>>a[i];
	--x;
	rotate(a,a+x,a+n);
	rotate(a,a+1,a+n);//set X last

	latermin[n]=INF;
	for(int i=n-1;i>=0;--i) latermin[i]=min(latermin[i+1],a[i]);

	evermin[0]=INF;
	REP(i,n) evermin[i+1]=min(evermin[i],a[i]);

	REP(i,n) if(latermin[i+1]>=a[i]+1 && evermin[i]>=a[i]){
		lint sum=0;
		for(int j=i+1;j<n;++j) a[j]-=a[i]+1,sum+=a[i]+1;
		REP(j,i) a[j]-=a[i],sum+=a[i];

		a[i]+=sum;

		rotate(a,a+n-1,a+n);
		if(x>0) rotate(a,a+n-x,a+n);
		REP(j,n) cout<<a[j]<<' ';
		cout<<endl;
		return 0;
	}
	while(1){};
	return 0;
}