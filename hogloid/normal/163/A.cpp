#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef long double ld;
typedef pair<int,int> pi;
lint dp[5005][5005];
char s[5005],t[5005];
const lint mod=1000000007;
int main(){
	scanf("%s%s",s,t);
	int n=strlen(s),m=strlen(t);
	int res=0;
	REP(i,n+1){
		dp[i][0]=1;
		REP(j,m){
			dp[i][j+1]+=dp[i][j],dp[i][j+1]%=mod;
			if(t[j]==s[i]) dp[i+1][j+1]+=dp[i][j],dp[i+1][j+1]%=mod;
		}
		res+=dp[i][m]-1;
		res=(res%mod+mod)%mod;
	}
	res=(res%mod+mod)%mod;
	printf("%d\n",res);
	return 0;
}