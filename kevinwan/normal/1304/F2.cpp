#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=3e5+10;
const int inf=0x3f3f3f3f;
int a[60][20010],p[60][20010];
int dp[60][20010],pm[20010],sm[20010];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]),p[i][j]=p[i][j-1]+a[i][j];
    for(int i=1;i<=m-k+1;i++)dp[1][i]=p[1][i+k-1]-p[1][i-1];
    for(int j=1,i=1;j<=m-k+1;j++)pm[j]=max(pm[j-1],dp[i][j]+p[i+1][j+k-1]-p[i+1][j-1]);
    for(int j=m-k+1,i=1;j>=1;j--)sm[j]=max(sm[j+1],dp[i][j]+p[i+1][j+k-1]-p[i+1][j-1]);
    for(int i=2;i<=n;i++){
        deque<int>s;
        for(int j=1;j<=m-k+1;j++){
            while(s.size()&&j-s.front()>=k)s.pop_front();
            while(s.size()&&dp[i-1][s.back()]-p[i][s.back()-1]<=dp[i-1][j]-p[i][j-1])s.pop_back();
            s.push_back(j);
            dp[i][j]=max(dp[i][j],dp[i-1][s.front()]+p[i][j+k-1]-p[i][s.front()-1]);
            if(j-k>=1)dp[i][j]=max(dp[i][j],pm[j-k]+p[i][j+k-1]-p[i][j-1]);
        }
        s.clear();
        for(int j=m-k+1;j>=1;j--){
            while(s.size()&&s.front()-j>=k)s.pop_front();
            while(s.size()&&dp[i-1][s.back()]+p[i][s.back()+k-1]<=dp[i-1][j]+p[i][j+k-1])s.pop_back();
            s.push_back(j);
            dp[i][j]=max(dp[i][j],dp[i-1][s.front()]+p[i][s.front()+k-1]-p[i][j-1]);
            if(j+k<=m)dp[i][j]=max(dp[i][j],sm[j+k]+p[i][j+k-1]-p[i][j-1]);
        }
        for(int j=1;j<=m-k+1;j++)pm[j]=max(pm[j-1],dp[i][j]+p[i+1][j+k-1]-p[i+1][j-1]);
        for(int j=m-k+1;j>=1;j--)sm[j]=max(sm[j+1],dp[i][j]+p[i+1][j+k-1]-p[i+1][j-1]);
    }
    printf("%d\n",sm[1]);
}