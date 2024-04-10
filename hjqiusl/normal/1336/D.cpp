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
// #define int ll
#define N 105
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
pa A[N];
int ans[N];
int n,nowx,nowy;
int gt(int x)
{
    for (int i=1;i;i++)
        if (i*(i-1)==x*2) return i;
}
pa query(int x)
{
    cout<<"+ "<<x<<endl;
    int a=0,b=0;
    cin>>a>>b;
    return mp(a,b);
}
void BellaKira()
{
    cin>>n;
    cin>>nowx>>nowy;
    for (int i=1;i<n;i++)
    {
        A[i]=query(i);
        A[i].fi-=nowx,A[i].se-=nowy;
        nowx=A[i].fi+nowx,nowy=A[i].se+nowy;
        if (A[i].fi!=0)
        {
            ans[i]=gt(A[i].fi);
        }
    }
    pa now=query(1);
    now.fi-=nowx,now.se-=nowy;
    nowx=nowx+now.fi,nowy=now.se+nowy;
    if (now.fi)
    {
        ans[1]=gt(now.fi)-1;
    }
    int nowd=now.se-A[1].se-1;
    if (ans[2]) ans[3]=nowd-ans[2];
    else if (ans[3]) ans[2]=nowd-ans[3];
    else
    {
        if (nowd==0) ans[2]=ans[3]=0;
        else if (nowd==2) ans[2]=ans[3]=1;
        else if (A[2].se) ans[3]=1,ans[2]=0;
        else ans[2]=1,ans[3]=0;
    }
    for (int i=4;i<n;i++)
    {
        if (ans[i]) continue;
        if (A[i-1].se-(ans[i-2]+1)*(ans[i-3]+1)>0) ans[i]=1;
        else ans[i]=0;
    }
    ans[n]=A[n-1].se/(ans[n-2]+1)-ans[n-3]-1;
    cout<<"! ";for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;


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

*/