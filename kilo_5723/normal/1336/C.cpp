#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int maxn=3e3+5;
ll dp[maxn][maxn];
char a[maxn],b[maxn];
bool fit(char a,char b){ return !b||a==b; }
int main(){
    int i,j,n,m;
    ll ans;
    scanf("%s%s",a,b);
    n=strlen(a); m=strlen(b);
    for (i=0;i<n;i++) dp[0][i]=fit(a[0],b[i])<<1;
    for (i=1;i<n;i++) for (j=0;j<n-i;j++)
        dp[i][j]=(fit(a[i],b[j])*dp[i-1][j+1]+fit(a[i],b[j+i])*dp[i-1][j])%mod;
    ans=0;
    for (i=m-1;i<n;i++) ans+=dp[i][0];
    printf("%lld\n",ans%mod);
    return 0;
}