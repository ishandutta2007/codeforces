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
int ar[25];

char dp[24][1<<23];
inline void chmin(char& a,char b){
	if(a>b) a=b;
}

int perm[25];
bool cmp(int a,int b){
	return ar[a]<ar[b];
}
int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	REP(i,n) perm[i]=i;
	sort(perm,perm+n,cmp);

	memset(dp,120,sizeof(dp));
	dp[1][1]=3;

	int res=INF;
	REP(i,n+1){
		for(int j=(1<<i)-1;j>=0;--j) if(dp[i][j]<100){
			int val=dp[i][j]/2,flag=dp[i][j]%2;
			flag^=1;
			if(flag){
				REP(k,i-1) if(j>>k&1) chmin(dp[i][j^(1<<k)],dp[i][j]+1-2);
			}

			if(i==n) {
				res=min(val,res);
				continue;
			}

			int cnt=0;
			REP(k,i) if(j>>k&1) ++cnt;

			int k2=n-1;
			REP(k,n) if(j>>perm[k]&1){
				while(k2>=0 && ar[perm[k2]]+ar[perm[k]]>ar[i]) --k2;
				if(k2<k) break;
				if(j>>perm[k2]&1 && ar[perm[k2]]+ar[perm[k]]==ar[i]){
					if(cnt+1>val){
						chmin(dp[i+1][j|(1<<i)],val*2+2);
					}
					else chmin(dp[i+1][j|(1<<i)],val*2+3);
				}
			}
		}
	}
	
	if(res==INF) res=-1;
	printf("%d\n",(int)res);



	return 0;
}