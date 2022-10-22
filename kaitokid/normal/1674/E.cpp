#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009];
bool ch(int x,int y,int r)
{
    x=max(0,x-r);
    y=max(0,y-r);
    return (x+y)<=r;
}
int go(int x,int y)
{
    int l=1,r=x+y;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(ch(x,y,mid))r=mid;
        else l=mid+1;
    }
    return l;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ans=INT_MAX;
        for(int i=0;i+2<n;i++)
        ans=min(ans,(a[i]+a[i+2]+1)/2);
       // cout<<ans<<endl;
        for(int i=0;i+1<n;i++)
        ans=min(ans,go(a[i],a[i+1]));
        sort(a,a+n);
        ans=min(ans,(a[0]+1)/2+(a[1]+1)/2);
        cout<<ans<<endl;



    return 0;
}