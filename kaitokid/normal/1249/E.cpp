#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,c,ans[200005],a[200009],b[200009],d=-1;
bool bl=false;
int main()
{
    cin>>n>>c;
    for(int i=1;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++)cin>>b[i];
    d=c;
    for(int i=1;i<n;i++)
    {
        if(bl){
            if(b[i]<=a[i]){ans[i]=ans[i-1]+b[i];}
            else {ans[i]=ans[i-1]+a[i];bl=false;d=min(c,b[i]-a[i]);}
            continue;
        }
if(a[i]<b[i]+min(d,c)){ans[i]=a[i]+ans[i-1];d=min(c,d+b[i]-a[i]);continue;}
ans[i]=ans[i-1]+b[i]+min(d,c);
bl=true;

    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return 0;
}