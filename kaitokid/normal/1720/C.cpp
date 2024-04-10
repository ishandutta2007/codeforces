#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[509][509];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n,m;
    cin>>n>>m;
    int ans=0,mn=3;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        char c;
        cin>>c;
        a[i][j]=c-'0';
        if(a[i][j]==1)ans++;
    }
  for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
  {
       if((i+1<n)&&(j+1<m))mn=min(mn,(a[i][j]==1)+(a[i+1][j]==1)+(a[i][j+1]==1));
       if((i-1>=0)&&(j+1<m))mn=min(mn,(a[i][j]==1)+(a[i-1][j]==1)+(a[i][j+1]==1));
       if((i+1<n)&&(j-1>=0))mn=min(mn,(a[i][j]==1)+(a[i+1][j]==1)+(a[i][j-1]==1));
       if((i-1>=0)&&(j-1>=0))mn=min(mn,(a[i][j]==1)+(a[i-1][j]==1)+(a[i][j-1]==1));
  }
  if(mn<=1){cout<<ans<<endl;continue;}
  ans-=(mn-1);
  cout<<ans<<endl;
}
return 0;
}