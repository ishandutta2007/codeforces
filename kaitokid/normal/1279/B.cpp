#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,s;
ll a[200009];
int main()
{
   ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    cin>>n>>s;
    int ans=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
        bool bl=false;
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[ans])ans=i;
        if(s<a[i]){cout<<ans+1<<endl;bl=true; break;}
        s-=a[i];
    }
    if(!bl)cout<<0<<endl;
}
    return 0;
}