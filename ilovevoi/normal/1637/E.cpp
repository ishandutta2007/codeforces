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
#define F(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=3e5+30;
const ll mod=1e9+7;
const ll base=500;

/// you will be the best but now you just are trash
/// goal 3/7

ll a[maxn];
ll cnt[maxn];
vector<ll> adj[maxn];
vector<ll> gr[maxn];

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
    ll t;
    cin>> t;
    while (t--)
    {
        ll n , m;
        cin>> n>> m;
        vector<ll> vt;
        F(i,1,n)
        {
         cin>> a[i];
         vt.pb(a[i]);
        }
        sort(vt.begin(),vt.end());
        vt.resize(unique(vt.begin(),vt.end())-vt.begin());
        F(i,1,n)
        {
            a[i]=lower_bound(vt.begin(),vt.end(),a[i])-vt.begin();
            cnt[a[i]]++;
        }
        F(i,1,m)
        {
            ll x, y;
            cin>>x>> y;
            x=lower_bound(vt.begin(),vt.end(),x)-vt.begin();
            y=lower_bound(vt.begin(),vt.end(),y)-vt.begin();
            adj[x].pb(y);
            adj[y].pb(x);
        }
        ll len=vt.size();
        ll ans=0;
        F(i,0,len-1) adj[i].pb(i);
        vector<ll> vt1;
        for (int i=0;i<=len-1;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            if (cnt[i]>base)
            {
                ll pre=0;
                F(j,0,len-1)
                {
                    while (pre<adj[i].size()&&vt[adj[i][pre]]<vt[j]) pre++;
                    if (pre<adj[i].size()&&vt[adj[i][pre]]==vt[j]) continue;
                    ans=max(ans,(cnt[i]+cnt[j])*(vt[i]+vt[j]));
                }
            }
            else
            {
                gr[cnt[i]].pb(i);
                vt1.pb(cnt[i]);
            }
        }
        sort(vt1.begin(),vt1.end());
        vt1.resize(unique(vt1.begin(),vt1.end())-vt1.begin());
        for (ll t=0;t<vt1.size();t++)
        {
            ll i=vt1[t];
            if (!gr[i].size()) continue;
            for (ll t1=0;t1<vt1.size();t1++)
            {
                ll j=vt1[t1];
                if (!gr[j].size()) continue;
                for (auto to:gr[i])
                {
                    ll pre=adj[to].size()-1;
                   /* if (vt[to]==4)
                    {
                        for (auto to1:adj[to])
                        {
                            cout <<vt[to1]<<" chkp"<<endl;
                        }
                    }*/
                    for (int k=gr[j].size()-1;k>=0;k--)
                    {
                        while (pre>=0&&adj[to][pre]>gr[j][k]) pre--;
                        if (pre>=0&&adj[to][pre]==gr[j][k]) continue;
                     //   cout <<vt[to]<<" "<<vt[gr[j][k]]<<" chk1"<<endl;
                      /*  if ((i+j)*(vt[to]+vt[gr[j][k]])==20)
                        {
                            cout <<i<<" "<<j<<" "<<vt[to]<<" "<<vt[gr[j][k]]<<" "<<cnt[to]<<" "<<cnt[gr[j][k]]<<" "<<pre<<" "<<adj[to][pre]<<" "<<gr[j][k]<<endl;
                            for (auto to1:adj[to])
                            {
                                cout<<to1<<" chk1"<<endl;
                            }
                            for (auto to1:gr[j])
                            {
                                cout <<to1<<" chk2"<<endl;
                            }
                        }*/
                        ans=max(ans,(i+j)*(vt[to]+vt[gr[j][k]]));
                        break;
                    }
                }
            }
        }
        for (auto to:vt1) gr[to].clear();
        for (int i=0;i<=len;i++) adj[i].clear(),cnt[i]=0;
        cout <<ans<<endl;
    }
}