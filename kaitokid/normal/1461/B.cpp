#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans[509][509],lf[509][509],ri[509][509];
string s[509];
int main()
{
    ios::sync_with_stdio(0);
int t,n,m;
cin>>t;
while(t--)
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.'){lf[i][j]=0;continue;}
            if(j==0)lf[i][j]=1;
            else lf[i][j]=1+lf[i][j-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(s[i][j]=='.'){ri[i][j]=0;continue;}
            if(j==m-1)ri[i][j]=1;
            else ri[i][j]=1+ri[i][j+1];
        }
    }
    int res=0;
  for(int i=0;i<m;i++)
        if(s[0][i]=='*'){ans[0][i]=1;res++;}
        else ans[0][i]=0;
  for(int i=1;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          ans[i][j]=min(min(lf[i][j],ri[i][j]),ans[i-1][j]+1);
          res+=ans[i][j];
      }
  }
  cout<<res<<endl;


}
    return 0;
}