#include<bits/stdc++.h>
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
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll r=0,mx=a[0];
        for(int i=1;i<n;i++)
            mx=max(mx,a[i]-a[i-1]);


        cout<<mx<<endl;
    }
    return 0;
}