#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {

     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
         cout<<i<<" ";
         for(int j=n;j>=1;j--)if(j!=i)cout<<j<<" ";
         cout<<endl;
     }
    }
    return 0;
}