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
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
string a[N];
int s[N];
int q;
signed main()
{
	IOS;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=' '+a[i];
	}
	for (int i=1;i<n;i++)
		for (int j=2;j<=m;j++)
			if (a[i][j]=='X'&&a[i+1][j-1]=='X') s[j]++;
	for (int i=2;i<=m;i++) s[i]+=s[i-1];
	cin>>q;
	while (q--)
	{
    int l,r;
    cin>>l>>r;
		if (s[r]-s[l]!=0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
				
}
/*
4 5
..XXX
...X.
...X.
...X.
5
1 3
3 3
4 5
5 5
1 5

1 4
XX.X
1
1 4

*/