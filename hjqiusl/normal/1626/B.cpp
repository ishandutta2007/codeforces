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
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
void BellaKira()
{
	string st;
	cin>>st;
	int lst=-2;
	int lst1=0;
	for (int i=0;i+1<st.size();i++)
	{
		if (st[i]+st[i+1]-'0'-'0'>=10)
		{
			lst=-1;
			lst1=i;
		} else
		{
			if (lst==-2) lst=i;
		}
	}
	if (lst!=-1)
	{
			string ans="";
			int i=lst;
			for (int j=0;j<lst;j++) ans+=st[j];
			// cout<<(st[i]-'0'+st[i+1]-'0')<<" "<<lst<<endl;
			ans+=char((st[i]-'0'+st[i+1]-'0')+'0');
			for (int j=i+2;j<st.size();j++) ans+=st[j];
			cout<<ans<<endl;
			lst=-1;
	}
	else
	{
			string ans="";
			int i=lst1;
			for (int j=0;j<i;j++) ans+=st[j];
			ans+=char((st[i]-'0'+st[i+1]-'0')/10+'0');
			ans+=char((st[i]-'0'+st[i+1]-'0')%10+'0');
			for (int j=i+2;j<st.size();j++) ans+=st[j];
			cout<<ans<<endl;
			lst=-1;
	}
		
		
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