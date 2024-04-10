#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
// const int mod=1e9+7;
// #define inf 0x3f3f3f3f
#define inf 0x3f3f3f3f3f3f3f3fll
// #define DEBUG
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const double eps=1e-8;
int main()
{
    #ifdef DEBUG
    freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        struct node
        {
            int l,r,id;
        };
        vector<node>vc1,vc2;
        for(int i=1;i<=n;++i)
        {
            int c,l,r;cin>>c>>l>>r;
            if(c==0)
                vc1.push_back({l,r,i});
            else vc2.push_back({l,r,i});
        }
        vector<int>f(n+1);
        iota(f.begin(),f.end(),0);
        function<int(int)>getf=[&](int x){return f[x]==x?x:f[x]=getf(f[x]);};
        auto sol=[&](vector<node>&vc1,vector<node>&vc2)
        {
            sort(vc1.begin(),vc1.end(),[&](node &x,node &y){
                return x.l<y.l;
            });
            vector<int>vis(vc1.size());
            auto lowerbound=[&](int val,int op)
            {
                int l=0,r=vc1.size();
                while(l<r)
                {
                    int mid=(l+r)>>1;
                    if((op?vc1[mid].r:vc1[mid].l)>=val) r=mid;
                    else l=mid+1;
                }
                return r;
            };
            for(auto &[l,r,id]:vc2)
            {
                int x=lowerbound(l,0);
                int y=lowerbound(r+1,0)-1;
                if(x<=y)
                {
                    f[getf(id)]=getf(vc1[x].id);
                    vis[x]++;
                    vis[y]--;
                }
            };
            for(int i=0;i+1<vc1.size();++i)
            {
                if(i) vis[i]+=vis[i-1];
                if(vis[i]) f[getf(vc1[i].id)]=getf(vc1[i+1].id);
            }
            sort(vc1.begin(),vc1.end(),[&](node &x,node &y){
                return x.r<y.r;
            });
            vis.clear();
            vis.resize(vc1.size(),0);
            for(auto &[l,r,id]:vc2)
            {
                int x=lowerbound(l,1);
                int y=lowerbound(r+1,1)-1;
                if(x<=y)
                {
                    f[getf(id)]=getf(vc1[x].id);
                    vis[x]++;
                    vis[y]--;
                }
            };
            for(int i=0;i+1<vc1.size();++i)
            {
                if(i) vis[i]+=vis[i-1];
                if(vis[i]) f[getf(vc1[i].id)]=getf(vc1[i+1].id);
            }
        };
        sol(vc1,vc2);
        sol(vc2,vc1);
        int ans=0;
        for(int i=1;i<=n;++i) ans+=f[i]==i;
        cout<<ans<<'\n';
    }
}