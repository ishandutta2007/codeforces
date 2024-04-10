#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100009],b[100009];
bool ch(int x)
{
    int f=x+n;
    int u=f-(f/4);
    int sum=0;
    int g=u;
    sum+=min(x,g)*100;
    g-=min(x,g);
    for(int i=0;i<g;i++)sum+=a[i];
   for(int i=0;i<min(n,u);i++)sum-=b[i];
   return (sum>=0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        reverse(a,a+n);
        reverse(b,b+n);
        int l=0,r=5*n;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(ch(mid))r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
        }
    return 0;
}