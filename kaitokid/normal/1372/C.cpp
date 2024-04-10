#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int mx=-1,mn=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)mx=i;
        if(a[i]!=i&&mn==-1)mn=i;
    }
    if(mx==-1){cout<<0<<endl;continue;}
    bool bl=false;
    for(int i=mn;i<=mx;i++)
        if(a[i]==i)bl=true;
    if(bl)cout<<2<<endl;
    else cout<<1<<endl;
    }
    return 0;

}