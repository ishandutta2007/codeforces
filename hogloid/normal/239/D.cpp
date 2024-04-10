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
static const int INF =1000000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
pi a[100005];
int h;
int n;
int ans[100005];
int main(){
	cin>>n>>h;
	REP(i,n) cin>>a[i].fr,a[i].sc=i;
	sort(a,a+n);
	
	if(n==2){
		printf("%d\n",0);
		printf("%d %d\n",1,1);
		return 0;
	}

	int res=INF;
	pi range;
	{
		int minval=min(a[1].fr+a[2].fr,a[0].fr+a[1].fr+h),
			maxval=max(a[n-1].fr+a[n-2].fr,a[0].fr+a[n-1].fr+h);
		if(maxval-minval<res){
			res=maxval-minval;
			range=mp(1,n-1);
		}
	}
	{
		int minval=a[0].fr+a[1].fr,maxval=a[n-1].fr+a[n-2].fr;
		if(maxval-minval<res){
			res=maxval-minval;
			range=mp(0,n-1);
		}
	}

	for(int i=1;i<n-1;++i){//[1...i]
		int minval=min(a[0].fr+a[1].fr+h,a[0].fr+a[i+1].fr);
		if(i>=2) minval=min(minval,a[2].fr+a[1].fr);
		int maxval=-1;
		if(i<n-2) maxval=a[n-1].fr+a[n-2].fr;
		maxval=max(maxval,a[n-1].fr+a[i].fr+h);
		if(maxval-minval<res){
			range=mp(1,i);
			res=maxval-minval;
		}
	}

	printf("%d\n",res);
	REP(i,n) ans[i]=1;
	REP(i,n) if(range.fr<=i && i<=range.sc) ans[a[i].sc]=2;

	REP(i,n) printf("%d%c",ans[i],i==n-1?'\n':' ');

	return 0;
}