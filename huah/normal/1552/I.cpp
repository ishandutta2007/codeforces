#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=105,mod=998244353;
int f[N];
class PQ_tree
{
    public:
        int n,tot,rt;
        bitset<N>vis;
        bool flag;
        struct node
        {
            vector<int>son;
            bool type;
            int op;
        }t[N<<2];
        int newnode(int type)
        {
            tot++;t[tot].type=type;t[tot].son.clear();return tot;
        }
        void init(int _n)
        {
            flag=true;
            n=_n;
            rt=tot=n+1;
            t[rt].type=0;
            for(int i=1;i<=n+1;i++) t[i].son.clear();
            for(int i=1;i<=n;i++) t[rt].son.push_back(i);
        }
        void dfs1(int u)
        {
            if(u<=n) t[u].op=vis[u]?2:1;
            else 
            {
                t[u].op=0;
                for(int v:t[u].son)
                {
                    dfs1(v);
                    t[u].op|=t[v].op;
                }
            }
        }
        void dfs2(int u,int lim)
        {
            if(!flag||t[u].op!=3) return;
            vector<int>vc[4];
            for(int v:t[u].son) vc[t[v].op].push_back(v);
            if((lim!=0)+vc[3].size()>=3) {flag=false;return;}
            if(!lim&&vc[2].size()+vc[3].size()<=1)
            {
                for(int x:vc[2]) dfs2(x,0);
                for(int x:vc[3]) dfs2(x,0);
                return;
            }
            if(t[u].type)
            {
                vector<int>s=t[u].son;
                t[u].son.clear();
                if(t[s[0]].op==2||t[s.back()].op==1)
                    reverse(s.begin(),s.end());
                int now=0;
                for(int v:s)
                {
                    if(t[v].op==1)
                    {
                        t[u].son.push_back(v);
                        now+=now==1;
                    }
                    else if(t[v].op==2)
                    {
                        t[u].son.push_back(v);
                        now+=!now;
                        if(now==2)
                        {
                            flag=false;return;
                        }
                    }
                    else
                    {
                        if(now==2) {flag=false;return;}
                        now++;
                        dfs2(v,3-now);
                        t[u].son.insert(t[u].son.end(),t[v].son.begin(),t[v].son.end());
                    }
                }
                if(lim&&now==2){flag=false;return;}
                if(lim==1) reverse(t[u].son.begin(),t[u].son.end());
            }
            else
            {
                int z=-1;
                if(vc[2].size()==1) z=vc[2][0];
                else if(vc[2].size()>1) z=newnode(0),t[z].son=vc[2];
                vector<int>s;
                if(!vc[3].empty())
                {
                    dfs2(vc[3][0],2);
                    s.insert(s.end(),t[vc[3][0]].son.begin(),t[vc[3][0]].son.end());
                }
                if(z!=-1) s.push_back(z);
                if(vc[3].size()>1)
                {
                    dfs2(vc[3][1],1);
                    s.insert(s.end(),t[vc[3][1]].son.begin(),t[vc[3][1]].son.end());
                }
                if(vc[1].empty())
                {
                    if(lim==1) reverse(s.begin(),s.end());
                    t[u].type=1,t[u].son=s; 
                }
                else
                {
                    if(lim)
                    {
                        t[u].son.clear();
                        t[u].type=1;
                        z=vc[1][0];
                        if(vc[1].size()>1)
                        {
                            z=++tot,t[z].type=0,t[z].son=vc[1];
                        }
                        t[u].son.push_back(z);
                        t[u].son.insert(t[u].son.end(),s.begin(),s.end());
                        if(lim==1)reverse(t[u].son.begin(),t[u].son.end());
                    }
                    else
                    {
                        z=s[0];
                        if(s.size()>1)z=++tot,t[z].son=s,t[z].type=1;
                        t[u].son=vc[1],t[u].son.push_back(z);    
                    }
                }
            }
        }
        void ins(bitset<N>&s)
        {
            if(!flag) return;
            vis=s;
            dfs1(rt);
            dfs2(rt,0);
        }
        int cal(int u)
        {
            int ans=1;
            if(!t[u].type) ans=f[t[u].son.size()];
            else if(t[u].son.size()>1) ans=2;
            for(int v:t[u].son) ans=1ll*ans*cal(v)%mod;
            return ans;
        }
        int getans()
        {
            if(!flag) return 0;
            return cal(rt);
        }
}T;
void sol(int cas)
{
    f[0]=1;
    for(int i=1;i<N;i++) f[i]=1ll*f[i-1]*i%mod;
    int n,m;sc(n,m);
    T.init(n);
    for(int i=1;i<=m;i++)
    {
        int k;sc(k);
        bitset<N>bs;
        while(k--)
        {
            int x;sc(x);
            bs[x]=1;
        }
        T.ins(bs);
    }
    printf("%d\n",T.getans());
}
int main()
{
//   freopen("1.in", "r",stdin);
  // freopen("2.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  // scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/