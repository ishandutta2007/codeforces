#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[200009],n,m;
bool ch(int x)
{
    ll d=0;
    for(int i=1;i<=n;i++)
    {
        if(fr[i]>=x){d+=x;continue;}
        d+=fr[i]+(x-fr[i])/2;
    }
    return (d>=m);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

    cin>>n>>m;
    for(int i=1;i<=n;i++)fr[i]=0;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        fr[x]++;
    }
    int l=0,r=2*m;
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