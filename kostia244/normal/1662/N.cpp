#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=1510;

int x[N*N],y[N*N];
int xs[N],xb[N],ys[N],yb[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int a;
            cin>>a;
            x[a]=i;
            y[a]=j;
        }
    for(int i=1;i<=n;i++)
        xb[i]=yb[i]=n;
    int ans=0;
    for(int a=1;a<=n*n;a++)
    {
        int i=x[a],j=y[a];
        xb[i]--;
        yb[j]--;
        ans+=xs[i]*yb[j]+xb[i]*ys[j];
        xs[i]++;
        ys[j]++;
    }
    cout<<ans/2;
}