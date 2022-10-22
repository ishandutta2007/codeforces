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

const ll maxn=3e5+10;
const ll mod=998244353;
const ll base=2e9+10000;

/// you will be the best but now you just are trash
/// goal 3/7
map<ll,ll> mp;
map<ll,vector<ll>> adj[maxn];
ll len[maxn];
string ans[maxn];

vector<ll> adj1[maxn];
map<pll,ll> mp1;
map<pll,ll> mp2;
map<ll,ll> mp3;
ll cntnw;
ll get1(ll x)
{
   if (mp3.count(x))
   {
       return mp3[x];
   }
   else
   {
       cntnw++;
       return mp3[x]=cntnw;
   }
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
    ll m;
    cin>> m;
    cntnw=m;
    for (int i=1;i<=m;i++)
    {
        cin>> len[i];
        F(j,0,len[i]-1)
        {
            ans[i].pb('L');
            ll x;
            cin>> x;
            mp[x]++;
            adj[i][x].pb(j);
        }
    }
    for (auto to:mp)
    {
        if (to.ss%2==1)
        {
            cout <<"NO"<<endl;
            return 0;
        }
    }
    for (int i=1;i<=m;i++)
    {
        vector<pll> vt;
        ll cl=len[i]/2;
        ll cl1=cl;
        for (auto to:adj[i])
        {
            if (to.ss.size()%2==0)
            {
                ll p=to.ss.size()/2;
                cl-=p;
                cl1-=p;
                for (int j=0;j<p;j++)
                {
                    ans[i][to.ss[j]]='L';
                }
                for (int j=p;j<to.ss.size();j++)
                {
                    ans[i][to.ss[j]]='R';
                }
            }
            else
            {
                ll p=to.ss.size()/2;
                cl-=p;
                cl1-=p;
                for (int j=0;j<p;j++)
                {
                    ans[i][to.ss[j]]='L';
                }
                for (int j=p;j<to.ss.size()-1;j++)
                {
                    ans[i][to.ss[j]]='R';
                }
                ll idnw=get1(to.ff);
                adj1[i].pb(idnw);
                adj1[idnw].pb(i);
                mp1[make_pair(i,idnw)]=1;
                mp1[make_pair(idnw,i)]=1;
                mp2[make_pair(i,idnw)]=to.ss.back();
                mp2[make_pair(idnw,i)]=to.ss.back();
               // cout <<i<<" "<<idnw<<endl;
            }
        }
    }
    for (int i=1;i<=cntnw;i++)
    {
        if (adj1[i].size())
        {
            stack<ll> st;
            st.push(i);
            vector<ll> vt;
            while (!st.empty())
            {
                auto p=st.top();
                while (adj1[p].size()&&mp1[make_pair(p,adj1[p].back())]==0)
                {
                    adj1[p].pop_back();
                }
                if (adj1[p].size())
                {
                    st.push(adj1[p].back());
                    mp1[make_pair(p,adj1[p].back())]=0;
                    mp1[make_pair(adj1[p].back(),p)]=0;
                }
                else
                {
                    st.pop();
                    vt.pb(p);
                }
            }
            for (int i=0;i<vt.size()-1;i++)
            {
                ll nw=min(vt[i],vt[i+1]);
                if (i%2==0)
                {
                    ans[nw][mp2[make_pair(vt[i],vt[i+1])]]='L';
                }
                else
                {
                    ans[nw][mp2[make_pair(vt[i],vt[i+1])]]='R';
                }
            }
        }
    }
    cout <<"YES"<<endl;
    for (int i=1;i<=m;i++)
    {
        cout <<ans[i]<<endl;
    }
}