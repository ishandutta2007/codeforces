//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
string st;
int n,nx[N],sta[N],tp;
bool cmp(int x,int y)
{
	int i=x,j=y;
	while (i<=n&&j<=n&&st[i]==st[j])
	{
		i=nx[i+1],j=nx[j+1];
	}
	if(i<=n&&j<=n)return st[i]<=st[j];
	return i>n&&j<=n;
}
void LYC_music()
{
	cin>>st;
	n=st.length();
	st=' '+st;
	sta[++tp]=n+1;
	nx[n+1]=n+1;
	for (int i=n;i>=1;i--)
	{
		nx[i]=i;
		if (st[i]==')')
		{
			sta[++tp]=i;
		} else
		{
			tp--;
			if (!tp)
			{
				sta[++tp]=i;
			} else
			{
				if (cmp(i,sta[tp])) sta[tp]=i;
				else nx[i]=sta[tp];
			}
		}
	}
	for (int i=1;i<=n;i=nx[i+1]) cout<<st[i];
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/