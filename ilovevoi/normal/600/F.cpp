/*#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")*/

#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define For(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e3+100;
const ll mod=998244353  ;
const ll base=1e9;

/// you will be the best but now you just are trash
/// goal 3/7


ll a, b, m;
ll nxt[maxn][maxn];
ll cnt[maxn];

ll x[maxn*maxn];
ll y[maxn*maxn];
ll res[maxn*maxn];
void dfs(ll pre,ll c1,ll c2)
{

    ll h=nxt[pre][c1];
    assert(h>0);
    ll nxt1=y[h]+x[h]-pre;
    assert(pre==x[h]||pre==y[h]);
    if (nxt[nxt1][c2])
    {
        dfs(nxt1,c2,c1);
    }
    else
    {
        nxt[nxt1][c1]=0;
    }
    nxt[pre][c2]=h;
    nxt[nxt1][c2]=h;
    /*if (h==2&&c2==1&&(pre==1||nxt1==1))
    {
        cout <<"cdjthe"<<endl;
    }*/
    res[h]=c2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    memset(nxt,0,sizeof(nxt));
    cin>> a>> b>> m;
    for (int i=1; i<=m; i++)
    {
        cin>> x[i]>> y[i];
        y[i]+=a;
        cnt[x[i]]++;
        cnt[y[i]]++;
    }
    ll mx=0;
    for (int i=1; i<=a+b; i++)
    {
        mx=max(mx,cnt[i]);
    }
    for (int i=1; i<=m; i++)
    {
        ll c1=-1,c2=-1;
        bool chk=false;
        for (ll j=1; j<=mx; j++)
        {
            if (!nxt[x[i]][j]&&!nxt[y[i]][j])
            {
                res[i]=j;
                nxt[x[i]][j]=i;
                nxt[y[i]][j]=i;
                chk=true;
                break;
            }
            if (!nxt[x[i]][j]&&nxt[y[i]][j])
            {
                c2=j;
            }
            if (nxt[x[i]][j]&&!nxt[y[i]][j])
            {
                c1=j;
            }
        }
       // cout <<i<<" "<<nxt[1][1]<<" wtfchk"<<endl;
        if (!chk)
        {

            dfs(x[i],c1,c2);

            nxt[x[i]][c1]=i;
            nxt[y[i]][c1]=i;

            res[i]=c1;
           /* for (int t=1;t<=i;t++)
            {
                cout <<res[t]<<" "<<t<<" chk2"<<endl;
            }
            //  cout <<nxt[1][1]<<" wtfchk"<<endl;
            for (int i=1;i<=a+b;i++)
            {
                cout <<nxt[i][1]<<" "<<nxt[i][2]<<" chk3"<<endl;
            }*/
        }
    }
    cout <<mx<<endl;
    for (int i=1;i<=m;i++)
    {
        cout <<res[i]<<" ";
    }
}