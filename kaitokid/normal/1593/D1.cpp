#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[400009];
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

    if(a[0]==a[n-1]){cout<<-1<<endl;continue;}
    int ans=a[1]-a[0];
    for(int i=1;i<n;i++)ans=__gcd(ans,a[i]-a[i-1]);
    cout<<ans<<endl;

    }
    return 0;
}