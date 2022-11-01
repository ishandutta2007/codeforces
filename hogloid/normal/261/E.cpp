//thx for wjmzbmr's solution
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
int l,r,p,m;

int prime[30];
bool isprime(int a){
	if(a==1) return false;
	for(int i=2;i<a;++i) if(a%i==0) return false;
	return true;
}
int all[3000005];
int dp[3000000],able[3000000];
int n;
void dfs(int ind,lint sum){
	if(sum>r) return ;
	if(ind==m){
		all[n++]=sum;
		return;
	}
	dfs(ind+1,sum);
	dfs(ind,sum*prime[ind]);
}
int main(){
	scanf("%d%d%d",&l,&r,&p);

	m=0;
	for(int i=2;i<=100;++i) if(isprime(i)) prime[m++]=i;

	dfs(0,1);
	
	sort(all,all+n);
	
	REP(i,n) dp[i]=INF,able[i]=0;
	dp[0]=0;
	for(int i=2;i<=p;++i){
		int k=0;
		REP(j,n){
			while(k<n && all[k]<all[j]*(lint)i) ++k;
			if(k==n) break;
			if(all[k]==all[j]*(lint)i){
				dp[k]=min(dp[k],dp[j]+1);
				if(dp[k]+i<=p) able[k]=1;
			}
		}
	}
	int res=0;
	REP(i,n) if(all[i]>=l && able[i]) ++res;
	cout<<res<<endl;

	return 0;
}