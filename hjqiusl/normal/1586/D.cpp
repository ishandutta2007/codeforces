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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N];
signed main()
{
	cin>>n;
	a[n]=1;
	for (int i=1;i<=n;i++)
	{
		cout<<"? ";
		for (int j=1;j<n;j++)
		{
			cout<<n<<" ";
		}
		cout<<i<<endl;
		int k;
		cin>>k;
		if (k!=0)
		{
			a[n]=n-i+1;
			break;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (i==a[n]) continue;
		cout<<"? ";
		for (int j=1;j<n;j++) cout<<a[n]<<" ";
		cout<<i<<endl;
		int k;
		cin>>k;
		a[k]=i;
	}
	cout<<"! ";
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
	
}
/*

*/