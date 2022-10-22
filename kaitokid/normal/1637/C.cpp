#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        if((n==3) && ((a[2]%2)==1)){cout<<-1<<endl;continue;}
        bool ans=false;
        ll res=0;
        for(int i=2;i<n;i++)
        {
            if(a[i]!=1)ans=true;
            res+=(a[i]+1)/2;
        }
        if(ans)cout<<res<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}