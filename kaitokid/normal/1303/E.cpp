#include <bits/stdc++.h>

using namespace std;
int dp[409][409];
string s,t1,t2,t;
int n,m1,m2,m;
int go(int i,int j)
{


 if(i==-1&&j==0)return 0;
if(i==-1)return -2;
if(dp[i][j]!=-1)return dp[i][j];
 int ans1=go(i-1,j);

if(ans1!=-2&&ans1<t2.size()){if(s[i]==t2[ans1])ans1++;}
int ans2=-2;
if(j>0&&s[i]==t1[j-1])
 ans2=go(i-1,j-1);

 return dp[i][j]=max(ans1,ans2);
}
int v(int x)
{
    t1="";
    t2="";
    for(int i=0;i<=x;i++)t1+=t[i];
    for(int i=x+1;i<m;i++)t2+=t[i];
m1=t1.size();
m2=t2.size();

for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)dp[i][j]=-1;
return go(n-1,m1);
}
int main()
{
   int q;
   cin>>q;
   while(q--)
   {
       cin>>s>>t;
       n=s.size(),m=t.size();

       bool bl=false;
       for(int i=0;i<m;i++){if(v(i)==m-i-1){bl=true;break;}}
       if(bl)cout<<"YES\n";
       else cout<<"NO\n";

   }

    return 0;
}