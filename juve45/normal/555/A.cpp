#include <bits/stdc++.h>

#define DMAX 100010
#define pb push_back

using namespace std;

int n, m, k, a;
int ans, var, var2;
int use[DMAX], v[DMAX];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>m;
        for(int j=1;j<=m;j++)
        {
        cin>>a;
            v[i]++;
            use[a]=i;
        }
    }
    int iy=1;
    var=use[iy];
    while(iy!=n && use[iy]==use[iy+1])
    {
       iy++;
    }
    ans+=v[var]-iy;
    for(int i=1;i<=k;i++)
    {
        if(i==var)
            continue;
        ans+=v[i]-1;
    }
    ans+=n-iy;
    cout<<ans<<'\n';
    return 0;
}