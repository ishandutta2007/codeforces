#include <bits/stdc++.h>
#define DMAX 100005
using namespace std;

int pos[DMAX], f[DMAX], n, m, k;

int solve(int q)
{
    if(q==pos[1])
        return 1;
    else{
        int p=f[q];
        f[q]--;
        int aux=p-1;
        f[pos[aux]]++;
        pos[f[pos[aux]]]=pos[aux];
        pos[f[q]]=q;
        p--;
        return 1+p/k;
    }
}

int main()
{
cin>>n>>m>>k;
int x, a;
long long ans=0;
    for(int i=1;i<=n;i++)
        cin>>x, f[x]=i, pos[i]=x;

    for(int i=1;i<=m;i++)
    {
        cin>>a;
        ans+=1LL*solve(a);
    }

    cout<<ans;

    return 0;
}