#include <bits/stdc++.h>
#define DMAX 200005
using namespace std;

int n, a[DMAX], rt[DMAX], s[DMAX];
int m, k, p;
int root(int p)
{
    if(rt[p]!=p) rt[p]=root(rt[p]);
        return rt[p];
}

void solve(int k, int p)
{
    for(int i=p;i<=n && k>0;i=root(i))
    {
        int g=min(k, a[i]-s[i]);
        s[i]+=g;
        k-=g;
        if(s[i]==a[i] && i!=n)
            rt[i]=root(i+1);
        if(i==n && g==0)
            break;
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    cin>>n;

    for(int i=1; i<=n; i++)
        rt[i]=i;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>k;
        if(k==1)
        {
            cin>>k>>p;
            solve(p, k);
        }
        else
        {
            cin>>p;
            cout<<s[p]<<'\n';
        }
    }

    return 0;
}