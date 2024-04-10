#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009],n,t,k;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
    cin>>n>>k;
    k++;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll sum=0;
    for(int i=n-1;i>n-1-k;i--)
   {
       sum+=a[i];}

    cout<<sum<<endl;

    }
    return 0;
}