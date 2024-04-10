#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[300];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {  int n,ans=0;
       cin>>n;
       for(int i=1;i<=200;i++)fr[i]=2;
       fr[0]=1;
       for(int i=0;i<n;i++)
       {
           int x;
           cin>>x;
           x=abs(x);
           if(fr[x]>0)ans++;
           fr[x]--;
       }
       cout<<ans<<endl;}

    return 0;
}