#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;

        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int ans=1;
        for(int i=n-1;i>=0;i--)
        if(i+1>=a[i])ans=max(ans,i+2);
        cout<<ans<<endl;

    }
    return 0;
}