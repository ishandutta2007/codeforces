#include <bits/stdc++.h>

#define pb push_back

using namespace std;

vector <long long> v[100005];

long long n, use[100005], m, gr[100005], ans2, ans1, ok, ans;

bool dfs(long long k, long long depth)
{
    use[k]=2-depth%2;

    if(depth%2==0) ans1++;
    else ans2++;

    for(long long i=0;i<v[k].size();i++)
    {
        if(use[v[k][i]]==use[k])
            return true;
        if(use[v[k][i]]==0)
            if(dfs(v[k][i], depth+1))
            return true;
    }
    return false;
}

int main()
{
    long long a, b;
cin>>n>>m;

    if(m==0)
    {
        cout<<"3 "<<n*(n-1)*(n-2)/6<<'\n';
        return 0;
    }

    for(long long i=1;i<=m;i++)
    {
        cin>>a>>b;
        gr[a]++; if(gr[a]>=2)ok=1;
        gr[b]++; if(gr[b]>=2)ok=1;
        v[a].pb(b);
        v[b].pb(a);
    }

    for(long long i=1;i<=n;i++)
    {
        if(use[i]==0)
            if(dfs(i, 1))
            {
                cout<<"0 1\n";
                return 0;
            }
            else{
                ans+=(ans1-1)*ans1/2+(ans2-1)*ans2/2;
                ans1=0;
                ans2=0;
            }
    }

    if(ok!=0)
    {
        cout<<"1 "<<ans<<'\n';
        return 0;
    }

    cout<<2<<' '<<m*(n-2)<<'\n';

    return 0;
}