#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c[90][90];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int u=(n+1)/2;
        if(k>u){cout<<-1<<endl;continue;}
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)c[i][j]='.';
        int r=0;
        while(k>0)
        {
            c[r][r]='R';
            r+=2;
            k--;
        }
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)cout<<c[i][j];
          cout<<endl;
      }
    }
    return 0;
}