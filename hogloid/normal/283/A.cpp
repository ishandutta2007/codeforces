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

int add[200005];
int ar[200005],m;
int main(){
	double sum=0;
	scanf("%d",&n);
	m=1;
	REP(hoge,n){
		int t;
		scanf("%d",&t);
		if(t==1){
			int a,x;scanf("%d%d",&a,&x);
			sum+=a*x;
			add[a-1]+=x;
		}else if(t==2){
			int k;scanf("%d",&k);
			ar[m++]=k;
			sum+=k;
		}else if(t==3){
			add[m-2]+=add[m-1];
			sum-=add[m-1]+ar[m-1];
			add[m-1]=0;
			--m;
		}
		printf("%.10f\n",sum/m);
	}

	return 0;
}