#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
int n;
struct node{ll a,b,c;}nod[N];
ll dp[N][N],s;
bool operator<(node a,node b){return a.b>b.b;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll a,b,c;scanf("%I64d%I64d%I64d",&a,&b,&c);
        nod[i]=(node){a,b,c};
    }
    sort(nod+1,nod+n+1);
    for(int i=1;i<=n;i++){
        ll a=nod[i].a,b=nod[i].b,c=nod[i].c;
        dp[i][0]=max(dp[i-1][0],dp[i-1][0]+a-b*c);
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a-b*(j-1));
            dp[i][j]=max(dp[i][j],dp[i-1][j]+a-b*c);
        }
    }
    for(int i=0;i<=n;i++)s=max(s,dp[n][i]);
	printf("%I64d",s);
    return 0;
}