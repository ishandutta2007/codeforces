//The Hunting Party - Keys To The Kingdom
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
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
string st;
int n,ans;
void LYC_music()
{
	cin>>n;
	cin>>st;
	st=' '+st;
	ans=inf;
	for (int i=1;i<n;i++)
		if (st[i]=='a'&&st[i+1]=='a')
		{
			ans=min(ans,2);
		}
	for (int i=1;i<=n-2;i++)
	{
		if ((st[i]=='a')+(st[i+1]=='a')+(st[i+2]=='a')>=2) ans=min(ans,3);
	}
	for (int i=1;i<=n-3;i++)
	{
		int x=0,y=0,z=0;
		for (int j=i;j<=i+3;j++)
			if (st[j]=='a') x++;
			else if (st[j]=='b') y++;
			else if (st[j]=='c') z++;
//			cout<<i<<" "<<x<<" "<<y<<" "<<z<<endl;
		if (x>y&&x>z) ans=min(ans,4);
	}
	for (int i=1;i<=n-4;i++)
	{
		int x=0,y=0,z=0;
//		cout<<"?"<<i<<" "<<x<<" "<<y<<" "<<z<<endl;
		for (int j=i;j<=i+4;j++)
			if (st[j]=='a') x++;
			else if (st[j]=='b') y++;
			else if (st[j]=='c') z++;
		if (x>y&&x>z) ans=min(ans,5);
	}
	for (int i=1;i<=n-5;i++)
	{
		int x=0,y=0,z=0;
//		cout<<"?"<<i<<" "<<x<<" "<<y<<" "<<z<<endl;
		for (int j=i;j<=i+5;j++)
			if (st[j]=='a') x++;
			else if (st[j]=='b') y++;
			else if (st[j]=='c') z++;
		if (x>y&&x>z) ans=min(ans,6);
	}
	for (int i=1;i<=n-6;i++)
	{
		int x=0,y=0,z=0;
//		cout<<"?"<<i<<" "<<x<<" "<<y<<" "<<z<<endl;
		for (int j=i;j<=i+6;j++)
			if (st[j]=='a') x++;
			else if (st[j]=='b') y++;
			else if (st[j]=='c') z++;
		if (x>y&&x>z) ans=min(ans,7);
	}
	if (ans==inf) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/