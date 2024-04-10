#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
// const int mod=1e9+7;
// #define inf 0x3f3f3f3f
#define inf 0x3f3f3f3f3f3f3f3fll
// #define DEBUG
// inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const long double eps=1e-8;
template<typename T>
struct BIT
{
    int n;
    vector<T>t,lz;
    inline void init(int _n){n=_n;t.clear();lz.clear();t.resize(n+1);lz.resize(n+1);}
    inline void add(int x,T v)
    {
        int l=x;
        while(x<=n)
        {
            t[x]+=(x-l+1)*v;
            lz[x]+=v;
            x+=x&-x;
        }
    }
    inline void add(int l,int r,T v)
    {
        add(l,v);add(r+1,-v);
    }
    inline T query(int x)
    {
        int r=x;
        ll ans=0;
        while(x)
            ans+=t[x]+lz[x]*(r-x),x-=x&-x;
        return ans;
    }
    inline T query(int l,int r)
    {
        return query(r)-query(l-1);
    }
};
int main()
{
    #ifdef DEBUG
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    vector<int>p(n+1),pos(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>p[i];
        pos[p[i]]=i;
    }

    vector<int>l(n+1),r(n+1);
    stack<int>s;
    for(int i=1;i<=n;++i)
    {
        while(!s.empty()&&p[s.top()]<p[i]) s.pop();
        l[i]=s.empty()?0:s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=n;i>=1;--i)
    {
        while(!s.empty()&&p[s.top()]<p[i]) s.pop();
        r[i]=s.empty()?n+1:s.top();
        s.push(i);
    }

    struct node
    {
        int l,r1,r2;
    };
    vector<vector<node>>add(n+1),del(n+1);

    vector<vector<int>>fac(n+1);
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i)
        fac[j].push_back(i);
    auto addseg=[&](int l1,int l2,int r1,int r2)
    {
        add[l2].push_back({l2,r1,r2});
        del[l1].push_back({l2,r1,r2});
    };

    auto sol=[&](vector<pair<int,int>>&vc,int l,int r,int m)
    {
        sort(vc.begin(),vc.end());
        priority_queue<int,vector<int>,greater<int>>q,del;
        for(auto &[x,y]:vc) q.push(y);
        int pre=l-1;
        for(int i=0;i<vc.size();++i)
        {
            while(!del.empty()&&q.top()==del.top()) q.pop(),del.pop();
            if(min(m,vc[i].first)>pre)
            {
                addseg(pre+1,min(m,vc[i].first),max(q.top(),m),r);
                pre=min(m,vc[i].first);
            }
            del.push(vc[i].second);
        }
    };
    for(int i=1;i<=n;++i)
    {
        ++l[i];--r[i];
        vector<pair<int,int>>vc;
        for(int x:fac[p[i]])
        {
            if(x<p[i]/x)
            {
                int ll=pos[x],rr=pos[p[i]/x];
                if(ll>rr) swap(ll,rr);
                if(ll>=l[i]&&rr<=r[i])
                    vc.push_back({ll,rr});
            }
        }
        sol(vc,l[i],r[i],i);
    }

    vector<node>qs(q);
    for(int i=0;i<q;++i) cin>>qs[i].r1>>qs[i].r2,qs[i].l=i;
    sort(qs.begin(),qs.end(),[&](node &x,node &y){return x.r1<y.r1;});
    vector<ll>ans(q);

    BIT<ll> t1,t2,t3;
    t1.init(n);t2.init(n);t3.init(n);
    for(int i=n;i>=1;--i)
    {
        for(node &x:add[i])
        {
            t1.add(x.r1,x.r2,x.l);
            t2.add(x.r1,x.r2,1);
        }
        while(!qs.empty()&&qs.back().r1==i)
        {
            ans[qs.back().l]=t1.query(qs.back().r1,qs.back().r2)-1ll*(i-1)*t2.query(qs.back().r1,qs.back().r2);
            ans[qs.back().l]+=t3.query(qs.back().r1,qs.back().r2);
            qs.pop_back();
        }
        for(node &x:del[i])
        {
            t1.add(x.r1,x.r2,-x.l);
            t2.add(x.r1,x.r2,-1);
            t3.add(x.r1,x.r2,x.l-i+1);
        }
    }
    for(int i=0;i<q;++i) cout<<ans[i]<<'\n';
}
/*
val is the max val  of interval [l,r]
pi*pj=val => i in [l,r], j in [l,r]

*/