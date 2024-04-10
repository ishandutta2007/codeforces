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
#define N 8000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int mn[N];
pa mx[N];
int a[N],ans;
int n;
pa query(pa x,pa y)
{
	if (x.fi>y.fi) return {x.fi,max(y.fi,x.se)};
	return {y.fi,max(x.fi,y.se)};
}
bool check(int x)
{
	for (int i=x;i;i=(i-1)&x)
		if (mx[i].se>mn[x^i]) return 1;
	return mx[0].se>mn[x];
}
void LYC_music()
{
	memset(mn,0x3f,sizeof(mn));
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		mn[a[i]]=min(mn[a[i]],i);
		mx[a[i]]=query(mx[a[i]],{i,0});
	}
	int B=(1<<21);
	for (int j=0;j<21;j++)
		for (int i=0;i<B;i++)
			if (!((i>>j)&1))
				mn[i]=min(mn[i],mn[i^(1<<j)]),
				mx[i]=query(mx[i],mx[i^(1<<j)]);
//	return;
	ans=0;
	for (int i=20;i>=0;i--)
	{
		if (check(ans|(1<<i)))
		{
			ans|=(1<<i);
		}
	}
//	writeln(mx[0].se);
	writeln(ans);
		
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
4
2 8 4 7
*/