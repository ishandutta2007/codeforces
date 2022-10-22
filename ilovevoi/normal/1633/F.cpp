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
//#define endl "\n"
#define F(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e5+100;
const ll mod=1e9+7 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7
vector<pll> adj[maxn];
ll val[maxn];
ll siz[maxn];
ll id[maxn];
ll pos[maxn];
ll anc[maxn];
ll n;
ll dep[maxn];

void dfs(ll u,ll par)
{
    siz[u]=1;
    anc[u]=par;
    for (auto p:adj[u])
    {
        ll to=p.ff;
        ll w=p.ss;
        if (to==par)
            continue;
        dep[to]=dep[u]+1;
        dfs(to,u);
        val[to]=w;
        siz[u]+=siz[to];
    }
}
ll nc=1;
ll cid[maxn];
ll chd[maxn];
ll cnt=0;
void hld(ll u,ll par)
{
    cnt++;
    id[u]=cnt;
    pos[cnt]=u;
    cid[u]=nc;
    if (!chd[nc])
        chd[nc]=u;
    pll mx=make_pair(-1,-1);
    for (auto p:adj[u])
    {
        ll to=p.ff;
        ll w=p.ss;
        if (to==par)
            continue;
        mx=max(mx,make_pair(siz[to],to));
    }
    if (mx.ss!=-1)
        hld(mx.ss,u);
    for (auto p:adj[u])
    {
        ll to=p.ff;
        ll w=p.ss;
        if (to==par)
            continue;
        if (mx.ss==to)
            continue;
        nc++;
        hld(to,u);
    }
}
struct tk
{
    // pos[0] = vi tri co gia tri > 0 dau tien tai pos chan
    // pos[1] = vi tri co gia tri > 0 dau tien tai pos le
    // pos[2] = vi tri co gia tri > 1 dau tien
    ll pos[3];
    ll la;
    ll val[3];
    ll len;
    ll valnw;
    ll posval;
    tk()
    {
        posval=0;
        valnw=-1;
        len=0;
        for (int t=0; t<=2; t++)
            pos[t]=-1;
        la=-1;
        memset(val,0,sizeof(val));
    }
};
tk st[4*maxn];
tk mer(tk a,tk b)
{
    a.la=-1;
    b.la=-1;
    if (a.len==base)
        return b;
    if (b.len==base)
        return a;
    tk c;
    for (int t=0; t<=1; t++)
        c.pos[t]=max(a.pos[t^b.len],b.pos[t]);
    c.pos[2]=max(a.pos[2],b.pos[2]);
    c.len=(a.len+b.len)%2;
    for (int t=0; t<=1; t++)
        c.val[t]=a.val[t^b.len]+b.val[t];
    c.val[2]=(a.val[2]+b.val[2]);
    c.posval=max(a.posval,b.posval);
    return c;
}
void modify(ll id,ll left,ll right,ll la)
{
    st[id].la=la;
    st[id].val[2]=st[id].val[st[id].la];
    st[id].posval=0;
    for (int t=0; t<=2; t++)
        st[id].pos[t]=-1;
    if (st[id].la==1)
        st[id].pos[0]=right;
    else if (left!=right)
        st[id].pos[1]=right-1;
    if (st[id].la==0) st[id].posval=right;
    else if (left!=right) st[id].posval=right-1;
    st[id].valnw=st[id].la;
}
void dosth(ll id,ll left,ll right)
{
    if (st[id].la==-1)
        return ;
    ll mid=(left+right)/2 ;
    modify(id*2,left,mid,st[id].la^((right-mid)%2));
    modify(id*2+1,mid+1,right,st[id].la);
    st[id].la=-1;
}
void update(ll id,ll left,ll right,ll x,ll diff)
{
    if (x>right||x<left)
        return ;
    if (left==right)
    {
        ll node=pos[x];
        st[id].posval=0;
        st[id].la=-1;
        st[id].len=1;
        st[id].valnw+=diff;
        st[id].val[0]=val[node];
        st[id].val[1]=0;
        st[id].val[2]=0;
        for (int t=0;t<=2;t++) st[id].pos[t]=-1;
        if (!st[id].valnw)
            st[id].val[2]=val[node],st[id].posval=left;
        if (st[id].valnw)
            st[id].pos[0]=left;
        if (st[id].valnw>=2)
            st[id].pos[2]=left;
        return ;
    }
    dosth(id,left,right);
    ll mid=(left+right)/2;
    update(id*2,left,mid,x,diff);
    update(id*2+1,mid+1,right,x,diff);
    st[id]=mer(st[id*2],st[id*2+1]);
}
void update1(ll id,ll left,ll right,ll x,ll y,ll diff)
{
    if (x>right||y<left)
        return ;
    if (x<=left&&y>=right)
    {
        ll nxt=(diff^((y-right)%2));
        modify(id,left,right,nxt);
        return ;
    }
    dosth(id,left,right);
    ll mid=(left+right)/2;
    update1(id*2,left,mid,x,y,diff);
    update1(id*2+1,mid+1,right,x,y,diff);
    st[id]=mer(st[id*2],st[id*2+1]);
}
tk get(ll id,ll left,ll right,ll x,ll y)
{
    tk c;
    c.len=base;
    if (x>right||y<left)
        return c;
    if (x<=left&&y>=right)
        return st[id];
    dosth(id,left,right);
    ll mid=(left+right)/2;
    return mer(get(id*2,left,mid,x,y),get(id*2+1,mid+1,right,x,y));
}
ll gethld(ll x)
{
    bool kt=(x==2);
    ll len=1;
    while (1)
    {
        tk p=get(1,1,n,id[chd[cid[x]]],id[x]);
       /* if (kt)
        {
            cout <<chd[cid[x]]<<" "<<cid[x]<<" "<<x<<" "<<id[x]<<" "<<id[chd[cid[x]]]<<" "<<len<<" "<<p.pos[0]<<" "<<p.pos[1]<<" wtf"<<endl;
        }*/
        if (p.pos[len]!=-1||p.pos[2]!=-1)
        {
            return max(p.pos[len],p.pos[2]);
        }
        if (cid[x]==1)
            return -1;
        len=(len^((id[x]-id[chd[cid[x]]]+1)%2));
        x=anc[chd[cid[x]]];
    }
}
void updatehld(ll x,ll y,ll diff)
{
    bool kt=(x==3);
    if (diff==1)
    {
        if ((dep[x]%2)==(dep[y]%2))
        {
            update(1,1,n,id[y],-1);
           /* if (kt)
            {
                cout <<"WTF"<<endl;
                auto p=get(1,1,n,id[1],id[1]);
                cout <<p.valnw<<" "<<p.pos[2]<<" "<<p.val[2]<<" chk1"<<endl;
                cout <<st[1].pos[2]<<endl;
            }*/
        }
        else
        {

            update(1,1,n,id[y],1);

        }
    }
    ll len=0;
  //  cout <<val[x]<<" chk2"<<endl;
    while (1)
    {
        if (cid[x]==cid[y])
        {
         //   cout <<id[y]+diff<<" "<<id[x]<<" "<<len<<" chk"<<endl;
            update1(1,1,n,id[y]+diff,id[x],len);
           // cout <<st[1].val[2]<<" chk3"<<endl;
            return ;
        }
      //  cout <<chd[cid[x]]<<" "<<cid[x]<<" "<<id[chd[cid[x]]]<<" "<<id[x]<<" chk1"<<endl;
        update1(1,1,n,id[chd[cid[x]]],id[x],len);
        len=(len^((id[x]-id[chd[cid[x]]]+1)%2));
        x=anc[chd[cid[x]]];
    }
}
ll getres()
{
    if (st[1].val[2]<base&&st[1].pos[2]==-1)
    {
        return st[1].val[2];
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("test.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    cin>> n;
    for (int i=1; i<=n-1; i++)
    {
        ll x, y;
        cin>>x>> y;
        adj[x].pb(make_pair(y,i));
        adj[y].pb(make_pair(x,i));
    }
    val[1]=base;
    dfs(1,0);
    hld(1,0);
    update(1,1,n,id[1],1);
    while (1)
    {
        ll p;
        cin>> p;
        if (p==1)
        {
            ll x;
            cin>> x;
           /* if (x==2)
            {
                tk p=get(1,1,n,id[1],id[1]);
                tk p1=get(1,1,n,id[4],id[4]);
                cout <<p.val[2]<<" "<<p.valnw<<" "<<p.pos[0]<<" "<<p1.pos[0]<<" "<<p1.valnw<<" "<<p1.val[2]<<endl;
            }*/
           update(1,1,n,id[x],1);

            ll nxt=gethld(x);
            nxt=pos[nxt];
            if (nxt==-1)
            {
                updatehld(x,1,0);
            }
            else
            {
              //  cout <<x<<" "<<nxt<<" "<<cid[x]<<" "<<cid[nxt]<<" wtf"<<endl;
                updatehld(x,nxt,1);
            }

            cout <<getres()<<endl;
        }
        else if (p==2)
        {
            vector<ll> ans;
            if (getres())
            {
                ll pre=n;
                while (1)
                {
                    tk p=get(1,1,n,1,pre);
                  //  cout <<p.posval<<" wtf"<<endl;
                    if (p.posval)
                    {
                        pre=p.posval-1;
                        ans.pb(val[pos[p.posval]]);
                    }
                    else
                        break;
                }
            }
            sort(ans.begin(),ans.end());
            cout <<ans.size()<<" ";
            for (auto to:ans)
                cout <<to<<" ";
            cout <<endl;
        }
        else
        {
            break;
        }
    }
}
/*6
1 4
6 1
3 2
1 2
5 1
1 4
2
1 2
1 3
2
3

*/