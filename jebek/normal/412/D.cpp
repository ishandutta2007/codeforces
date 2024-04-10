#include <iostream>
#include<algorithm>
#include<map>

using namespace std;

/*void dp(int k)
{
    if(k==1)
    {
        int v=s.begin()->second;
        ne[0]=v;
        p[v]=0;
        p[n+1]=v;
        ne[v]=n+1;
        return;
    }

}*/

int n,m,ne[100000],p[100000];
map<int,bool>mark[100000];

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>v>>u;
        mark[v][u]=true;
    }
    ne[0]=1;
    p[1]=0;
    p[n+1]=1;
    ne[1]=n+1;
    for(int i=2;i<=n;i++)
    {
        int v=ne[0];
        if(!mark[i][v])
        {
            p[v]=i;
            ne[i]=v;
            ne[0]=i;
            p[i]=0;
            continue;
        }
        v=p[n+1];
        if(!mark[v][i])
        {
            ne[v]=i;
            p[i]=v;
            p[n+1]=i;
            ne[i]=n+1;
            continue;
        }
        v=ne[0];
        v=ne[v];
        while(mark[i][v])
            v=ne[v];
        int u=p[v];
        ne[u]=i;
        p[i]=u;
        ne[i]=v;
        p[v]=i;
    }
    int v=ne[0];
    for(int i=1;i<=n;i++)
    {
        cout<<v<<" ";
        v=ne[v];
    }
    cout<<endl;
}