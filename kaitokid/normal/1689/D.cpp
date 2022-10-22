#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[4];
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
    d[0]=d[1]=d[2]=d[3]=INT_MAX;
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
     {
         char c;
         cin>>c;
         if(c=='W')continue;
         d[0]=min(d[0],i+j);
         d[1]=min(d[1],i-j);
         d[2]=min(d[2],-i+j);
         d[3]=min(d[3],-i-j);
     }
     int x=1,y=1,ans=INT_MAX;
     for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
          int res=max(i+j-d[0],i-j-d[1]);
          res=max(res,max(-i+j-d[2],-i-j-d[3]));
          if(res<ans){ans=res,x=i,y=j;}
      }
      cout<<x+1<<" "<<y+1<<endl;
}

return 0;
}