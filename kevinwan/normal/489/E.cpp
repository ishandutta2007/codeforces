#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e3+10;
int a[mn],b[mn];
int bac[mn];
double dp[mn];
int n,l;
double eval(double r){
    fill(dp,dp+mn,1e300);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(dp[j]+sqrt(abs(l-(a[i]-a[j])))-r*b[i]<dp[i]){
                dp[i]=dp[j]+sqrt(abs(l-(a[i]-a[j])))-r*b[i];
                bac[i]=j;
            }
        }
    }
    return dp[n];
}
int main(){
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
    double cur=0;
    for(double i=1e6;i>=1e-12;i*=.5){
        if(eval(cur+i)>0)cur+=i;
    }
    vector<int>v;
    for(int i=n;i;i=bac[i])v.push_back(i);
    reverse(v.begin(),v.end());
    for(int x:v)printf("%d ",x);
}