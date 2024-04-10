//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],sum[N],f[N][5];
int j;
int ans;
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1],sum[i]^=a[i];
	memset(f,0x3f,sizeof(f));
	int X=((1ll<<21)-1);
	for (int now=20;now>=0;now--)
	{
		j=1;
		for (int i=1;i<=n;)
		{
			if ((a[i]>>now)%2==0) i++,j++;
			else
			{
				for (;j<=n;j++)
				{
					if ((a[j]>>now)%2==0) break;
				}
				for (int k=i-1;k<j-1;k++)
				{
					f[sum[k]&(X^((1ll<<(now+1))-1))][(k&1)]=min(f[sum[k]&(X^((1ll<<(now+1))-1))][(k&1)],k);
					ans=max(ans,k-f[sum[k+1]&(X^((1<<(now+1))-1))][(k&1)^1]+1);
				}
				for (int k=i-1;k<j-1;k++)
				{
					f[sum[k]&(X^((1ll<<(now+1))-1))][0]=inf;
					f[sum[k]&(X^((1ll<<(now+1))-1))][1]=inf;
				}
				i=j;
			}
		}
//		cout<<(X^((1ll<<(now+1))-1))<<" "<<now<<endl;
	}
	writeln(ans);
				
				
		
		
}
/*

*/