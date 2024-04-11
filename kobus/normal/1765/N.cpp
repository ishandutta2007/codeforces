#include "bits/stdc++.h"
#define MAXN 500009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;
 
typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int dp[MAXN][10];
char s[MAXN];
int main(){
	//freopen("file.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int n=strlen(s),k;
		scanf("%d",&k);
		for(int j=0;j<10;j++)
			dp[n][j]=n;
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<10;j++)
				dp[i][j]=dp[i+1][j];
			dp[i][s[i]-'0']=i;
		}
		int now=0,f=1;
		int rem=n-k;
		while(rem){
			for(int j=f;j<10;j++)
				if(n-dp[now][j]>=rem){
					printf("%d",j);
					now=dp[now][j]+1;
					break;
				}
			rem--;
			f=0;
		}
		puts("");
	}
	return 0;
}