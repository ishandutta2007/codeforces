#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int C = 100;
bool g[C+10][C+10];
void st()
{
    for (int i=1; i<=C; i++)
        g[i][i]=1;
    for (int i=1; i<=C; i++)
        for (int j=i+1; j<=C; j++)
            if ( ((j-i)&i) == (j-i))
                g[i][j]=1;
    for (int k=1; k<=C; k++)
        for (int i=1; i<=C; i++)
            for (int j=1; j<=C; j++)
                if (g[i][k])
                if (g[k][j])
                    g[i][j]=true;
}

bool check(int u, int v)
{
    if (u>v)
        return false;
    while (true)
    {
        if (((v-u)&u) == (v-u))
            return true;
        if (u==v)
            return true;
        if (u%2 == v%2)
        {
            u/=2;
            v/=2;
            continue;
        }
        if ((u%2==0) and (v%2==1))
            return false;
        else
        {
            int u0=u;
            int cnt =0;
            while (u0%2)
                cnt++, u0/=2;
            int add = (1ll<<cnt)-1;

            u+=add;
            u/=2;
            v/=2;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    st();
//    for (int i=1; i<=C; i++)
//        for (int j=1; j<=C; j++)
//            if (check(i, j) != g[i][j])
//                cout<<i<<" "<<j<<" "<<check(i, j)<<" "<<g[i][j]<<"\n";


    int q;
    cin>>q;
    while (q--)
    {
        int u, v;
        cin>>u>>v;
        if (check(u, v))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}