//The Hunting Party - Keys To The Kingdom
//~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
//#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
string st;
int s[N];
int b[N];
void What_will_Diana_eat_today()
{
	cin>>n>>m;
	swap(n,m);
	cin>>st;
	int len=st.size();
	st=' '+st;
	for (int i=1;i<=len;i++)
	{
		s[i]=s[i-1];
		if (st[i]=='L') s[i]--;
		else if (st[i]=='R') s[i]++;
		b[s[i]+1000000]=min(b[s[i]+1000000],i);
	}
	int x=0,ansx=1;
	for (int i=1;i<=n;i++)
	{
		int nowx=inf,nowy=inf;
		nowx=b[-i+1000000];
		nowy=b[n-i+1+1000000];
//		cout<<i<<" "<<nowx<<" "<<nowy<<endl;
		if (min(nowx,nowy)>x) ansx=i,
		x=max(x,min(nowx,nowy));
		if (x==inf) break;
	}
	for (int i=1;i<=len;i++) b[s[i]+1000000]=inf;
	for (int i=1;i<=len;i++)
	{
		s[i]=s[i-1];
		if (st[i]=='U') s[i]--;
		else if (st[i]=='D') s[i]++;
		b[s[i]+1000000]=min(b[s[i]+1000000],i);
	}
	int y=0,ansy=1;
	for (int i=1;i<=m;i++)
	{
		int nowx=inf,nowy=inf;
		nowx=b[-i+1000000];
		nowy=b[m-i+1+1000000];
		if (min(nowx,nowy)>y) ansy=i,
		y=max(y,min(nowx,nowy));
		if (y==inf) break;
	}
	for (int i=1;i<=len;i++) b[s[i]+1000000]=inf;
	cout<<ansy<<" "<<ansx<<endl;
}
signed main()
{
	IOS;
	for (int i=0;i<=2000000;i++) b[i]=inf;
	int T=1;
	cin>>T;
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*
1
3 2
ULURRLLRD
*/