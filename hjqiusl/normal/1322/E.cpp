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
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],b[N],ans;
int st[N][25],st1[N][25];
pa query(int l,int r)
{
	int t=log2(r-l+1);
	return mp(max(st[l][t],st[r-(1<<t)+1][t]),min(st1[l][t],st1[r-(1<<t)+1][t]));
}
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		st[i][0]=min(a[i],a[i+1]);
		st1[i][0]=max(a[i],a[i+1]);
	}
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<j)-1<n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]),
			st1[i][j]=min(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
	for (int i=1;i<=n;i++)
	{
		int l=1,r=min(i-1,n-i),now=0;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			pa u=query(i-mid,i+mid-1);
//			cout<<"?"<<i<<" "<<mid<<" "<<u.fi<<" "<<u.se<<endl/;
			if (u.fi<u.se)
			{
				now=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,now);
//		cout<<"?"<<i<<" "<<now<<endl;
		if (now==0)
		{
			b[i]=a[i];
			continue;
		}
		pa v=query(i-now,i+now-1);
		if (a[i]>=a[i-1])
		{
			if (now&1) b[i]=v.fi;
			else b[i]=v.se;
		}
		else
		{
			if (now&1) b[i]=v.se;
			else b[i]=v.fi;
		}
	}
	writeln(ans);
	for (int i=1;i<=n;i++) writesp(b[i]);
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