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
lint ar[5005];
int dp[5005];

bool check(lint a,lint b,int p2,int gap){
	if(p2<gap){
		b>>=p2;
		return a%b==0;
	}else{
		b>>=(gap);
		return a%(b*2)==b;
	}
}


int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	
	int res=INF;

	dp[0]=0;
	REPN(i,n,1){
		int p2=0;
		lint tmp=ar[i];
		while(tmp%2==0){
			++p2;
			tmp>>=1;
		}

		dp[i]=i;
		REP(j,i) if(check(ar[j],ar[i],p2,i-j)) dp[i]=min(dp[i],dp[j]+(i-j-1));
	}

	REP(i,n) res=min(res,n-1-i+dp[i]);

	cout<<res<<endl;

	return 0;
}