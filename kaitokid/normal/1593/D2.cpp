#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[400009];
int ans,r,n;
void ch(int st,int g)
{
    int f=1;
    for(int i=st+1;i<n;i++)if((a[i]-a[st])%g==0)f++;
    if(f>=r)ans=max(ans,g);
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
    sort(a,a+n);

    int fr=1;
    int mx=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])fr++;
        else {mx=max(mx,fr);fr=1;}
    }
    mx=max(mx,fr);
    r=n/2;
    if(mx>=r){cout<<-1<<endl;continue;}
     ans=1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
    {
        if(a[i]==a[j])continue;
        int u=a[j]-a[i];
        int g=sqrt(u);
        for(int q=1;q<=g;q++)
        if(u%q==0){ch(i,q);ch(i,u/q);}
    }
    cout<<ans<<endl;
    }
    return 0;
}