//~~remotejudge
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
#define mod 1000000007
#define int ll
#define N 500005
// #define M 35
using namespace std;
inline char gc(){static char buf[1<<21],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
string st;
int l[N],r[N],fa[N];
int vis[N][2];
int ans[2][N][15];
int cnt;
int ct[15];
int gf(int x)
{
    if (x==fa[x]) return x;
    fa[x]=gf(fa[x]);
    return fa[x];
}
void BellaKira()
{
    cin>>n>>m;
    cin>>st;
    st='>'+st;
    r[0]=1;
    for (int i=1;i<=n;i++) fa[i]=i,l[i]=i-1,r[i]=i+1;
    int p=0,fx=1;
    memset(ans,0x3f,sizeof(ans));
    for (;p<=n;)
    {
        // cerr<<p<<endl;
        if (cnt==n) break;
        int nxtp=0;
        if (st[p]>='0'&&st[p]<='9')
        {
            ct[st[p]-'0']++;
            if (st[p]=='0')
            {
                l[r[p]]=l[p];
                r[l[p]]=r[p];
                cnt++;
            } else st[p]-=1;
            nxtp=fx?r[p]:l[p];
        }
        else
        {
            if (st[p]=='>') fx=1;
            else fx=0;
            nxtp=(fx?r[p]:l[p]);
            if (p&&!(st[nxtp]>='0'&&st[nxtp]<='9'))
            {
                l[r[p]]=l[p];
                r[l[p]]=r[p];
                cnt++;
            }
        }
        if (fx&&!vis[nxtp][1])
        {
            for (int i=0;i<=9;i++) ans[1][nxtp][i]=ct[i];
            vis[nxtp][1]=1;
        }
        if (!fx)
        {
            int j=gf(nxtp)+1;
            while (j<=p)
            {
                // cout<<"??"<<j<<endl;
                for (int i=0;i<=9;i++) ans[0][j][i]=ct[i];
                vis[j][0]=1;
                if (gf(j)!=gf(j-1)) fa[gf(j-1)]=gf(j);
                j=gf(j)+1;
            }
        }
        p=nxtp;
    }
    for (int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        for (int j=0;j<10;j++)
        {
            if (vis[l][0]) cout<<(min(ans[0][l][j],ans[1][r+1][j]))-ans[1][l][j]<<" ";
            else cout<<(ans[1][r+1][j]-ans[1][l][j])<<" ";
		}
        cout<<endl;
    }

}  
signed main()
{
    IOS;
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*
*/