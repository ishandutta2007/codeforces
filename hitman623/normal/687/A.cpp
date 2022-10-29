#include <bits/stdc++.h>
#define pb push_back
#define bs binary_search
using namespace std;
map <long , vector < long > > l;
long visi[100005]={0},s1=0,s2=0;
map < long ,long > a,b;
map < long ,long > ::iterator it;
void dfs(long node)
{
    visi[node]=1;
    long i,f=0;
    if(a[node]==1) f=1;
    for(i=0;i<l[node].size();i++)
    {
        if(visi[l[node][i]])
        {
            if(f==0)
            {if(a[l[node][i]])continue;
            else {cout<<-1;exit(0);}}
            else
            {if(b[l[node][i]])continue;
            else {cout<<-1;exit(0);}}
        }
        if(f) {b[l[node][i]]=1;s2++;dfs(l[node][i]);}
        else {a[l[node][i]]=1;s1++;dfs(l[node][i]);}
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n,m,x,y,i;
    cin>>n>>m;
    for(i=0;i<m;++i)
       {cin>>x>>y;
        l[x].pb(y);
        l[y].pb(x);}
    for(i=1;i<=n;++i)
        if(!visi[i])
        {a[i]=1;s1++;
         dfs(i);}
    cout<<s2<<endl;
    for(it=b.begin();it!=b.end();it++)
        if(it->second)cout<<(it->first)<<" ";
        cout<<endl;
    cout<<s1<<endl;
    for(it=a.begin();it!=a.end();it++)
        if(it->second)cout<<it->first<<" ";
    return 0;
}