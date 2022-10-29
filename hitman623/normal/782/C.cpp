#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
map < long , vector < long > > a;
long visi[200005]={0},color[200005],m=0;
void dfs(long node,long pc)
{
    long i,c=1;
    visi[node]=1;
    for(i=0;i<a[node].size();++i)
        {
            if(!visi[a[node][i]])
            {
                if(c==color[node] || c==pc) c++;
                if(c==color[node] || c==pc) c++;
                color[a[node][i]]=c;
                c++;
                dfs(a[node][i],color[node]);
            }
        }
    m=max(m,c-1);
}
int main()
{
    long n,i,x,y,node=1;
    cin>>n;
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    color[node]=1;
    dfs(node,1);
    cout<<m<<endl;
    for(i=1;i<=n;++i)
    cout<<color[i]<<" ";
    return 0;
}