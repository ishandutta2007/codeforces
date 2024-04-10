#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009],n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%n){cout<<-1<<endl;continue;}
        sum/=n;
        int ans=0;
        for(int i=0;i<n;i++)if(a[i]>sum)ans++;
        cout<<ans<<endl;
    }
    return 0;
}