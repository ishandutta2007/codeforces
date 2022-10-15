/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5+1;
const int H = 20;

int a[N], c[N];
int par[N][H];

void solve()
{
    int q;
    cin>>q>>a[0]>>c[0];

    for(int j=0; j<H; j++) par[0][j]=-1;

    int typ;
    for(int i=1; i<=q; i++)
    {
        cin>>typ;
        if(typ==1)
        {
            int p;
            cin>>p>>a[i]>>c[i];

            par[i][0]=p;
            for(int j=1; j<H; j++)
            {
                int x = par[i][j-1];
                if(x==-1) par[i][j]=-1;
                else par[i][j] = par[x][j-1];
            }
        }
        else
        {
            int v, w;
            cin>>v>>w;

            int take=0;
            int cost=0;

            while(w!=0)
            {
                int z = v;
                for(int j=H-1; j>=0; j--)
                {
                    int x = par[z][j];
                    if(x==-1 || a[x]==0) continue;
                    z = x;
                }

                int tmp = min(a[z], w);
                a[z]-=tmp;
                w-=tmp;

                take += tmp;
                cost += (tmp*c[z]);
                if(z==v) break;
            }

            cout<<take<<" "<<cost<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}