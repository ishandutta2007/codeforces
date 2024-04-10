#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
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
int k,b,n;
int seq[100005],sum[100005];
lint sum2[100005];
int main(){
	scanf("%d%d%d",&k,&b,&n);
	REP(i,n){
		int a;scanf("%d",&a);
		sum[i+1]=sum[i]+a;
		sum2[i+1]=sum2[i]+a;
		sum[i+1]%=(k-1);
	}
	lint res=0;
	if(b==0){
		REP(i,n){
			res+=upper_bound(sum2,sum2+n+1,sum2[i])-sum2;
			res-=i+1;
		}
		cout<<res<<endl;
		return 0;
	}else if(b==k-1){
		REP(i,n){
			res+=upper_bound(sum2,sum2+n+1,sum2[i])-sum2;
			res-=i+1;
		}
		res=-res;
	}
	map<int,int> later;
	REP(i,n+1) later[sum[i]]++;
	REP(i,n){
		--later[sum[i]];
		int want=(sum[i]+b)%(k-1);
		res+=later[want];
	}
	cout<<res<<endl;

	return 0;
}