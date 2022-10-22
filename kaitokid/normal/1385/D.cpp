#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
string s;
//int dp[131077][28][28];
int go(int l,int k,int x)
{
   // if(dp[l][k][x]!=-1)return dp[l][k][x];
    if(k==0){if(s[l]==char('a'+x))return 0;return 1;}

int r=l+(1<<k)-1;
int mid=l+(1<<(k-1))-1;
    int ans1=r-mid,ans2=r-mid;
    for(int i=l;i<=mid;i++)if(s[i]==char('a'+x))ans1--;
    ans1+=go(mid+1,k-1,x+1);
    for(int i=mid+1;i<=r;i++)if(s[i]==char('a'+x))ans2--;
    ans2+=go(l,k-1,x+1);
   // cout<<l<<" "<<r<<" "<<x<<" "<<ans1<<" "<<ans2<<endl;
return min(ans1,ans2);
}
int main()
{
ios::sync_with_stdio(0);
int t,n,x;
cin>>t;
while(t--)
{

   cin>>n>>s;
  /* for(int i=0;i<n;i++)
    for(int j=0;j<28;j++)
    for(int q=0;q<28;q++)dp[i][j][q]=-1;*/
   int r=log2(n);
   cout<<go(0,r,0)<<endl;

}
    return 0;
}