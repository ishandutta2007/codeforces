#include<bits/stdc++.h>
using namespace std;
int a[5050];
long long dfs(int l,int r,int delta)
{
    if(l==r)
        return 0;
    long long ans=r-l;
    int mn=*min_element(a+l,a+r);
    long long cost=mn-delta;
    int last=l;
    for(int i=l;i<r;i++)
        if(a[i]==mn)
        {
            cost+=dfs(last,i,mn);
            last=i+1;
        }
    cost+=dfs(last,r,mn);
    return min(ans,cost);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<dfs(0,n,0)<<endl;
    return 0;
}