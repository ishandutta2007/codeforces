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
#define N 3505
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int vis[N];
poly G[N];
int lst[N];
int nxt[N];
int ans;
int ccs[N];
int n;
void dfs(int k,int fa)
{
    // cout<<k<<" "<<fa<<" "<<nxt[fa]<<endl;
    vis[k]=1;
    for (auto u:G[k])
    {
        if (u==fa||u==lst[k]) continue;
        lst[u]=k;
        nxt[k]=u;
        if (!vis[u]) dfs(u,k);
    }
    if (!nxt[k]) nxt[k]=lst[k];
    // cout<<k<<" "<<fa<<" "<<nxt[fa]<<" "<<nxt[1]<<endl;
}
void calc(int x,int l,int r,int L,int R,int dp,int st)
{
    // cout<<x<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<dp<<" "<<st<<endl;
    if (x==st&&dp!=0)
    {
        if (ccs[x])
            ans=(ans+L*(n-R+1)*l*(n-r+1)*(dp/2));
        return;
    }
    if (dp%2==0)
    {
        if (dp)
        {
        if (x<=n)
        {
            int Lf=lst[st]-n;
            int Rf=nxt[x]-n;
            if (!(Lf>=L&&Lf<=R))
            {
                if (!(Rf>=L&&Rf<=R))
                {
                    int len1=L,len2=n-R+1;
                    if (Lf<L) len1=min(len1,L-Lf);
                    if (Rf<L) len1=min(len1,L-Rf);
                    if (Lf>R) len2=min(len2,Lf-R);
                    if (Rf>R) len2=min(len2,Rf-R);
                    ans=(ans+len1*len2*l*(n-r+1)*(dp/2));
                    // cout<<"?"<<st<<" "<<dp<<" "<<x<<" "<<ans<<endl;
                }
            }
        } else
        {
            int Lf=lst[st];
            int Rf=nxt[x];
            if (!(Lf>=l&&Lf<=r))
            {
                if (!(Rf>=l&&Rf<=r))
                {
                    int len1=l,len2=n-r+1;
                    if (Lf<l) len1=min(len1,l-Lf);
                    if (Rf<l) len1=min(len1,l-Rf);
                    if (Lf>r) len2=min(len2,Lf-r);
                    if (Rf>r) len2=min(len2,Rf-r);
                    ans=(ans+len1*len2*L*(n-R+1)*(dp/2));
                    // cout<<"?"<<st<<" "<<dp<<" "<<x<<" "<<ans<<endl;
                }
            }
        }

        }
    } else
    {
        if (x<=n)
        {
            int Lf=lst[st];
            int Rf=nxt[x]-n;
            if (!(Lf>=l&&Lf<=r))
                if (!(Rf>=L&&Rf<=R))
                {
                    int len1=l,len2=n-r+1,len3=L,len4=n-R+1;
                    if (Lf<l) len1=min(len1,l-Lf);
                    if (Lf>r) len2=min(len2,Lf-r);
                    if (Rf<L) len3=min(len3,L-Rf);
                    if (Rf>R) len4=min(len4,Rf-R);
                    ans=(ans+len1*len2*len3*len4*(dp/2+1));
                    // cout<<"?"<<st<<" "<<dp<<" "<<x<<" "<<ans<<" "<<Lf<<" "<<Rf<<endl;
                }
        } else
        {
            int Lf=lst[st]-n;
            int Rf=nxt[x];
            swap(Lf,Rf);
            if (!(Lf>=l&&Lf<=r))
                if (!(Rf>=L&&Rf<=R))
                {
                    int len1=l,len2=n-r+1,len3=L,len4=n-R+1;
                    if (Lf<l) len1=min(len1,l-Lf);
                    if (Lf>r) len2=min(len2,Lf-r);
                    if (Rf<L) len3=min(len3,L-Rf);
                    if (Rf>R) len4=min(len4,Rf-R);
                    ans=(ans+len1*len2*len3*len4*(dp/2+1));
                    // cout<<"?"<<st<<" "<<dp<<" "<<x<<" "<<ans<<" "<<Lf<<" "<<Rf<<" "<<len1<<" "<<len2<<" "<<len3<<" "<<len4<<" "<<L<<" "<<R<<endl;
                }
        }
    }
    if (x<=n)
    {
        calc(nxt[x],l,r,min(L,nxt[x]-n),max(R,nxt[x]-n),dp+1,st);
    } else
    {
        calc(nxt[x],min(l,nxt[x]),max(r,nxt[x]),L,R,dp+1,st);
    }
}
void BellaKira()
{
    n=read();
    for (int i=1;i<=2*n;i++)
    {
        int x=read(),y=read();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i=1;i<=2*n;i++)
        if (!vis[i]) dfs(i,0),ccs[i]=1;
    for (int i=1;i<=n;i++)
        calc(i,i,i,n+1,0,0,i);
    for (int i=n+1;i<=n+n;i++)
        calc(i,n+1,0,i-n,i-n,0,i);
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
2
1 3
1 4
2 3
2 4

*/