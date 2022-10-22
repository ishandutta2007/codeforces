//~~
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
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
void BellaKira()
{
	// cin>>n;
	int x=-1;
	int lstsm=0;
	for (int i=0;i<30;i++)
	{
		if (i==29)
		{
			cout<<"? "<<(-lstsm+(1ll<<i))+2<<" "<<(-lstsm+(1ll<<(i+1)))<<endl;
			int res;
			cin>>res;
			// res=__gcd((n-lstsm+(1ll<<i))+2,n+(-lstsm+(1ll<<(i+1))));
			// cout<<"?"<<res<<endl;
			if (res%3==0) lstsm+=(1ll<<i);
			break;
		}
		cout<<"? "<<(1ll<<(i+2))-lstsm<<" "<<(1ll<<(i+1))-lstsm<<endl;
		int res;
		// res=__gcd(n+(1ll<<(i+2))-lstsm,n+(1ll<<(i+1))-lstsm);
		cin>>res;
		if (res%(1ll<<i)==0&&(res%(1ll<<(i+1))!=0))
		{
			lstsm+=(1ll<<i);
		}
	}
	cout<<"! "<<lstsm<<endl;
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/