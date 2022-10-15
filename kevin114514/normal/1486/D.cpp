#include<bits/stdc++.h>
using namespace std;
int val[200200];
int psum[200200];
int n,k;
bool check(int mid)
{
    for(int i=1;i<=n;i++)
        if(val[i]>=mid)
            psum[i]=psum[i-1]+1;
        else    psum[i]=psum[i-1]-1;
    int mx=0;
    for(int i=k;i<=n;i++)
    {
        mx=min(mx,psum[i-k]);
        if(psum[i]>mx)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))
            l=mid;
        else    r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}