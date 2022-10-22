#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009],b[100009],n,k;
bool ch(int x)
{
    int d=k;
    for(int i=0;i<n;i++)
    if(a[i]<(x+1)/2){b[i]=1000000000;d--;}else b[i]=a[i];

    if(d<0)return false;
    for(int i=0;i+1<n;i++)
    {
        int g=d;
        if(b[i]<x)g--;
        if(b[i+1]<x)g--;
        if(g>=0)return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
       cin>>n>>k;
       for(int i=0;i<n;i++)cin>>a[i];

       int l=1,r=1000000000;
       while(l<r)
       {
           int mid=(l+r+1)/2;
           if(ch(mid))l=mid;
           else r=mid-1;
       }
       cout<<l<<endl;
    }
    return 0;
}