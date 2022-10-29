#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector < long > a[100005],q;
long visi[100005]={0},p[100005]={0};

void dfs(long node)
{
    long i;
    visi[node]=1;
    for(i=0;i<a[node].size();++i)
    {
        if(visi[a[node][i]] && p[a[node][i]]==0) {cout<<-1;exit(0);}
        dfs(a[node][i]);
        if(p[a[node][i]]==0)
        q.pb(a[node][i]);
        p[a[node][i]]=1;
    }
}
int main()
{
    long n,k,c[100005],i,j,x,t;
    cin>>n>>k;
    for(i=0;i<k;++i)
    cin>>c[i];
    for(i=1;i<=n;++i)
    {
        cin>>t;
        for(j=0;j<t;++j)
        {
            cin>>x;
            a[i].pb(x);
        }
    }
    for(i=0;i<k;++i)
    if(!visi[c[i]])
    {
        dfs(c[i]);
        q.pb(c[i]);
        p[c[i]]=1;
    }
    n=q.size();
    cout<<n<<endl;
    for(i=0;i<n;++i)
    cout<<q[i]<<" ";
    return 0;
}