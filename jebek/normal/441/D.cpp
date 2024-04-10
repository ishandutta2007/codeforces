#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=4000;
bool mark[MAXN],mark1[MAXN];
int f[MAXN],p,n,m,t,c[MAXN];

void dfs2(int v)
{
    mark[v]=true;
    if(!mark[f[v]])
        dfs2(f[v]);
}

void dfs1(int v)
{
    c[v]=t;
    mark1[v]=true;
    if(!mark1[f[v]])
        dfs1(f[v]);
}

void dfs(int v)
{
    c[v]=1;
    mark[v]=true;
    mark1[v]=true;
    if(!mark1[f[v]])
        dfs(f[v]);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p;
        f[i]=p;
    }
    cin>>m;
    m=n-m;
    t=1;
    dfs(1);
    for(int i=2;i<=n;i++)
        if(!mark1[i])
        {
            t++;
            dfs1(i);
        }
    if(t>m)
    {
        cout<<t-m<<endl;
        for(int i=2;i<=n && t>m;i++)
        {
            if(!mark[i])
            {
                t--;
                cout<<1<<" "<<i<<" ";
                dfs2(i);
            }
        }
        cout<<endl;
        return 0;
    }
    else if(t==m)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        cout<<m-t<<endl;
        for(int i=1;i<=n && t<m;i++)
        {
            if(f[i]==i)
                continue;
            for(int j=i+1;j<=n;j++)
                if(c[j]==c[i])
                {
                    cout<<i<<" "<<j<<" ";
                    t++;
                    swap(f[i],f[j]);
                    memset(mark1,false,sizeof mark1);
                    dfs1(i);
                    i--;
                }
        }
        cout<<endl;
        return 0;
    }
}