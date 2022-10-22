#include<bits/stdc++.h>
using namespace std;
int a[100009];
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
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int mx=0,fr=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1]){mx=max(mx,fr);fr=1;continue;}
            fr++;
        }
        mx=max(mx,fr);
        int ans=0;
        while(mx<n)
        {
            ans++;
            ans+=min(mx,n-mx);
            mx=min(2*mx,n);

        }
        cout<<ans<<endl;
    }
    return 0;
}