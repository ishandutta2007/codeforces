#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=10000;
bool mark[MAXN];
int h[MAXN],n,x[MAXN],y[MAXN],l,r,ans;

bool dfs(int v,int k)
{
    mark[v]=true;
    for(int i=0;i<n;i++)
    {
        if(i!=v && abs(x[i]-x[v])+abs(y[i]-y[v])>k)
        {
            if(!mark[i])
            {
                h[i]=1-h[v];
                if(!dfs(i,k))
                    return false;
            }
            else
            {
                if(h[i]==h[v])
                    return false;
            }
        }
    }
    return true;
}

bool check(int k)
{
    memset(mark,false,sizeof mark);
    memset(h,0,sizeof h);
    for(int i=0;i<n;i++)
        if(!mark[i])
            if(!dfs(i,k))
                return false;
    return true;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    l=0;r=10000;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l<<endl;
    ans=1;
    memset(mark,false,sizeof mark);
    memset(h,0,sizeof h);
    for(int i=0;i<n;i++)
        if(!mark[i])
        {
            dfs(i,l);
            ans=(ans*2)%1000000007;
        }
    cout<<ans<<endl;
}