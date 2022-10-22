#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10009];
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
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=0;
        for(int i=1;i<=k;i++)if(a[i]>k)ans++;
        cout<<ans<<endl;

    }
    return 0;
}