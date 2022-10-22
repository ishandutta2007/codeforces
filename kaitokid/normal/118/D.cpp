#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 int MOD=100000000;
int n1,n2,k[2];
int  d[209][13][4][209];
int dp(int i,int x,int s,int sum)
{

if(d[i][s][x][sum]!=-1)return d[i][s][x][sum];
if(i==n1+n2-1)return 1;
int ans=0;
if(x==0){
if(sum<n1&&s<k[0])ans+=dp(i+1,0,s+1,sum+1);
if(i+1-sum<n2)ans+=dp(i+1,1,1,sum);




}
if(x==1){
if(i+1-sum<n2&&s<k[1])ans+=dp(i+1,1,s+1,sum);
if(sum<n1)ans+=dp(i+1,0,1,sum+1);




}
d[i][s][x][sum]=(ans%100000000);
//cout<<i<<" "<<s<<" "<<x<<" "<<sum<<" "<<ans<<endl;
return ( ans%100000000);
}
int main()
{
ios::sync_with_stdio(0);
memset(d,-1,sizeof d);
cin>>n1>>n2>>k[0]>>k[1];
cout<<( dp(0,0,1,1)+dp(0,1,1,0))%MOD;
return 0;}