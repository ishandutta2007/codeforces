#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

vector<int>G[200];
bool mark[200];
long long n,m,a[200],b[200];
long long ans,w[200][200];

long long dfs(int v,long long k)
{
    mark[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            if(__gcd(a[u]/b[u],k)>1)
            {
                k=__gcd(a[u]/b[u],k);
                b[u]*=k;
                w[v][u]*=k;
                w[u][v]*=k;
                return k;
            }
            for(int j=0;j<G[u].size();j++)
            {
                int v1=G[u][j];
                if(!mark[v1] && __gcd(k,w[u][v1])>1)
                {
                    int x=dfs(v1,__gcd(k,w[u][v1]));
                    if(x>1)
                    {
                        w[v][u]*=x;
                        w[u][v]*=x;
                        w[u][v1]/=x;
                        w[v1][u]/=x;
                        return x;
                    }
                }
            }
        }
    }
    return 1;
}

long long f(int k)
{
    long long ans1=0;
    for(int i=2;i<=sqrt(k);i++)
    {
        while(k%i==0)
        {
            k/=i;
            ans1++;
        }
    }
    if(k>1)
        ans1++;
 //   cout<<ans1<<endl;
    return ans1;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=1;
    }
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>v>>u;
        w[v][u]=w[u][v]=1;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i+=2)
    {
        while(1)
        {
            long long k=a[i]/b[i];
            memset(mark,false,sizeof mark);
            k=dfs(i,k);
            if(k==1)
                break;
            b[i]*=k;
            ans+=f(k);
        }
    }
    cout<<ans<<endl;
}