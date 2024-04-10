#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],b[200009];
int n;
bool ch(int x)
{
    int u=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]+b[i]+1<x)continue;
        if(a[i]<u)continue;
        if(b[i]<x-u-1)continue;
        u++;
    }
    return (u>=x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=0;i<n;i++)cin>>b[i]>>a[i];
    int r=n,l=0;
    while(r>l)
    {
        int mid=(l+r+1)/2;
        if(ch(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;

    }
    return 0;
}