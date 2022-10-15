/*
K.D. Vinit  |,,|
K
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5;
const int L = 1200;
int a[N+1]={0};
int val[L+1][L+1];

void solve()
{
    int n;
    cin>>n;

    for(int i=0; i<=L; i++)
    {
        for(int j=0; j<=L; j++) val[i][j]=0;
    }

    for(int i=1; i<=n; i++)
    {
        int typ, x, y;
        cin>>typ>>x>>y;
        if(typ==1)
        {
            a[x]+=y;
            for(int i=1; i<=L; i++)
            {
                int z = x%i;
                val[i][z]+=y;
            }
        }
        else
        {
            if(x<=L) cout<<val[x][y]<<endl;
            else
            {
                int ans=0;
                for(int j=y; j<=N; j+=x) ans+=a[j];
                cout<<ans<<endl;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}