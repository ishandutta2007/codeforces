#include<bits/stdc++.h>
using namespace std;
string s[10];
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
        for(int i=0;i<n;i++)cin>>s[i];
        int lf=1e9,pp=1e9;
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
          if(s[i][j]=='R')lf=min(lf,i),pp=min(pp,j);
        if(s[lf][pp]=='R')cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
           }

    return 0;
}