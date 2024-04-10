#include <bits/stdc++.h>

using namespace std;
map < long ,vector <long > > a;
long n,b[200005],i,c=0,x,y;
long visi[200005]={0},m;
void dfs(long node,long c)
{
    long i;
    visi[node]=1;
    for(i=0;i<a[node].size();++i)
    {
        if(visi[a[node][i]])
        {
            if(a[node][i]!=c)
            {
                if(b[node]==a[node][i])
                    b[a[node][i]]=m==0?m=a[node][i]:m;
                else b[node]=(m==0)?m=node:m;
            }
        }
        else
        {
            dfs(a[node][i],node);
        }
    }
}
int main()
{

    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>b[i];
        if(b[i]==i) m=i;
        a[i].push_back(b[i]);
        a[b[i]].push_back(i);
    }
    if(m==0) c++;
    for(i=1;i<=n;i++)
    {
        if(visi[i]==0)
        {
            c++;
            dfs(i,i);
        }
    }
    cout<<c-1<<endl;
    c=0;
    for(i=1;i<=n;++i)
    {
        if(b[i]==i) b[i]=m;
        cout<<b[i]<<" ";
    }
    return 0;
}