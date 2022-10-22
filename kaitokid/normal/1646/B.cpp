#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009];
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
        sort(a+1,a+n+1);
        bool ans=false;
        for(int i=1;i<=n;i++)a[i]+=a[i-1];
        for(int i=0;2*i+1<=n;i++)
        {
            if(a[i+1]<a[n]-a[n-i]){ans=true;break;}

        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}