#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[39];
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
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;

    while(n>1)
    {
        int mx=0;
        for(int i=1;i<=n;i++)if(a[i]>a[mx])mx=i;
        if(mx==n){n--;continue;}
        if(mx==0){ans=-1;break;}
        ans++;
        a[mx]/=2;


    }
    cout<<ans<<endl;

    }

    return 0;

}