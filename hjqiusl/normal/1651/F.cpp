//~~
#define setI(x) freopen(x,"r",stdin)
#define setO(x) freopen(x,"w",stdout)
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
#define B 300005ll
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int rt[N];
int rt1[N];
int tp;
int sta[N];
int n,r[N],c[N],fl[N],nowfl[N];
int s[N];
int res[N];

int q,ans;
namespace sg1
{
    int cnt;
    int tr[10000005];
    int rson[10000005];
    int lson[10000005];
    void pushup(int k)
    {
        tr[k]=tr[lson[k]]+tr[rson[k]];
    }
    void update(int &k,int lst,int l,int r,int L,int x)
    {
        k=++cnt;
        tr[k]=tr[lst];
        lson[k]=lson[lst];
        rson[k]=rson[lst];
        if (l==r)
        {
            tr[k]=tr[k]+x;
            return;
        }
        int mid=l+(r-l)/2;
        if (L<=mid) update(lson[k],lson[lst],l,mid,L,x);
        else update(rson[k],rson[lst],mid+1,r,L,x);
        pushup(k);
    }
    int query(int lk,int rk,int l,int r,int L)
    {
        if (lk==rk) return 0;
        if (!rk) return 0;
        if (r<=L)
        {
            return tr[rk]-tr[lk];
        }
        int mid=l+(r-l)/2;
        int res=query(lson[lk],lson[rk],l,mid,L);
        if (mid<L)  
            res+=query(rson[lk],rson[rk],mid+1,r,L);
        return res;
    }
};
namespace sg2
{
    int cnt;
    int tr[10000005];
    int rson[10000005];
    int lson[10000005];
    void pushup(int k)
    {
        tr[k]=tr[lson[k]]+tr[rson[k]];
    }
    void update(int &k,int lst,int l,int r,int L,int x)
    {
        k=++cnt;
        tr[k]=tr[lst];
        lson[k]=lson[lst];
        rson[k]=rson[lst];
        if (l==r)
        {
            tr[k]=tr[k]+x;
            return;
        }
        int mid=l+(r-l)/2;
        if (L<=mid) update(lson[k],lson[lst],l,mid,L,x);
        else update(rson[k],rson[lst],mid+1,r,L,x);
        pushup(k);
    }
    int query(int lk,int rk,int l,int r,int L)
    {
        if (r<L) return 0;
        if (lk==rk) return 0;
        if (!rk) return 0;
        if (L<=l)
        {
            return tr[rk]-tr[lk];
        }
        int mid=l+(r-l)/2;
        int res=query(rson[lk],rson[rk],mid+1,r,L);
        if (L<=mid) 
            res+=query(lson[lk],lson[rk],l,mid,L);
        return res;
    }
};
void BellaKira()
{
    n=read();
    for (int i=1;i<=n;i++) 
    {
        c[i]=read(),r[i]=read();
        fl[i]=(c[i]-1)/r[i]+1;
        fl[i]=min(fl[i],B);
        s[i]=s[i-1]+c[i];
    }
    for (int i=1;i<=n;i++)
    {
        sg1::update(rt[i],rt[i-1],0,B,fl[i],c[i]);
        sg2::update(rt1[i],rt1[i-1],0,B,fl[i],r[i]);
    }
    q=read();
    sta[++tp]=n;
    nowfl[n]=inf;
    int lstt=0;
    for (int i=1;i<=q;i++)
    {
        int t=read(),h=read();
        int lstl=0;
        while (tp)
        {
            if (nowfl[sta[tp]]==inf)
            {
                int l=lstl+1,r=sta[tp];
                int now=r+1;
                while (l<=r)
                {
                    int mid=l+(r-l)/2;
                    if (s[mid]-s[lstl]>=h)
                    {
                        now=mid;
                        r=mid-1;
                    } else l=mid+1;
                }
                if (now==sta[tp]+1)
                {
                    h-=s[n]-s[lstl];
                    nowfl[n]=t;res[n]=0;
                } else
                {
                    if (now!=sta[tp]) sta[++tp]=now;
                    res[sta[tp]]=s[now]-s[lstl]-h;
                    nowfl[sta[tp]]=t;
                    if (now>1)
                    {
                        sta[++tp]=now-1;
                        nowfl[sta[tp]]=t;
                        res[sta[tp]]=0;
                    }
                    h=0;
                }
                break;
            } else
            if (!res[sta[tp]])
            {
                int nowt=t-nowfl[sta[tp]];
                int nowtt=sg1::query(rt[lstl],rt[sta[tp]],0,B,nowt)+
                            sg2::query(rt1[lstl],rt1[sta[tp]],0,B,nowt+1)*nowt;
                if (h>=nowtt)
                {
                    h-=nowtt;
                    nowfl[sta[tp]]=0;
                    res[sta[tp]]=0;
                    lstl=sta[tp];
                    tp--;
                    continue;
                } else
                {
                    int l=lstl+1,r=sta[tp];
                    int now=r+1;
                    while (l<=r)
                    {
                        int mid=l+(r-l)/2;
                        if (sg1::query(rt[lstl],rt[mid],0,B,nowt)+sg2::query(rt1[lstl],rt1[mid],0,B,nowt+1)*nowt>=h)
                        {
                            now=mid;
                            r=mid-1;
                        } else l=mid+1;
                    }
                    if (now!=sta[tp]) sta[++tp]=now;
                    res[sta[tp]]=sg1::query(rt[lstl],rt[now],0,B,nowt)+sg2::query(rt1[lstl],rt1[now],0,B,nowt+1)*nowt-h;
                    nowfl[sta[tp]]=t;
                    if (now>1)
                    {
                        sta[++tp]=now-1;
                        nowfl[sta[tp]]=t;
                        res[sta[tp]]=0;
                    }
                    h=0;
                    break;
                }
            } else
            {
                res[sta[tp]]+=(t-nowfl[sta[tp]])*r[sta[tp]];
                res[sta[tp]]=min(res[sta[tp]],c[sta[tp]]);
                if (res[sta[tp]]<=h)
                {
                    h-=res[sta[tp]];
                    res[sta[tp]]=0;
                    nowfl[sta[tp]]=0;
                    lstl=sta[tp];
                    tp--;
                    continue;
                } else
                {
                    res[sta[tp]]=res[sta[tp]]-h;
                    h=0;
                    nowfl[sta[tp]]=t;
                    break;
                }
            }   
        }
        if (!tp) sta[++tp]=n,nowfl[n]=t,res[n]=0;
        else
        {
            if (sta[tp]!=1)
            {
                int lst=sta[tp];
                sta[++tp]=lst-1;
                nowfl[lst-1]=t;
                res[lst-1]=0;
            }
        }
        ans+=h;
    }
    writeln(ans);
}
signed main()
{
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*
3
5 1
7 4
4 2
4
0 14
1 10
3 16
10 16
*/