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
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
string b[N],nowst,st,NOW;
void LYC_music()
{
	IOS;
	cin>>n;
	int ans=0;
	int sx=0,x=0,y=0,sy=0,allsm=1,lst=0;
	for (int i=1;i<=n;i++) cin>>b[i];
	nowst=b[n];
//	cout<<"!"<<NOW<<endl;
	for (int i=1;i<nowst.length();i++)
	{
		if (nowst[i]!=nowst[0]) allsm=0;
		if (nowst[i]!=nowst[i-1])
		{
			ans=max(ans,i-lst);
			if (lst==0) x=i;
			lst=i;
		}
	}
	if (allsm) ans=nowst.length(),x=y=ans;
	else ans=max(ans,max(x,y));
	y=nowst.length()-lst;
	sx=nowst[0];
	sy=nowst.back();
	ans=max(ans,(int)nowst.length()-lst);
	for (int i=n-1;i>=1;i--)
	{
		st=b[i];
		if (allsm)
		{
			allsm&=(st[0]==sx);
			for (int j=1;j<st.length();j++)
			{
				allsm&=(st[j]==st[0]);
			}
			if (allsm) x=y=st.length()*x+x+st.length(),ans=max(ans,x);
			else
			{
				int X=0,Y=0;
				for (int j=0;j<st.length();j++)
				{
					if (st[j]!=sx)
					{
						X+=x;
						break;
					}
					X+=x;
					X+=1;
				}
				for (int j=st.length()-1;j>=0;j--)
				{
					if (st[j]!=sx)
					{
						Y+=x;
						break;
					}
					Y+=x;
					Y+=1;
				}
				int lst=0;
				for (int i=0;i<st.length();i++)
				{
					lst+=x;
					ans=max(ans,lst);
					if (st[i]==sx)
					{
						lst+=1;
					} else lst=0;
				}
				ans=max(ans,lst+x);
				x=X,y=Y;
				ans=max(ans,max(x,y));
			}
		} else
		{
//			int x=0;
			for (int j=0;j<st.length();j++)
			{
				if (st[j]==sy&&st[j]==sx)
				{
					ans=max(ans,x+y+1);
				} else
				if (st[j]==sy)
				{
					ans=max(ans,y+1);
				} else 
				if (st[j]==sx)
					ans=max(ans,x+1);
			}
		}
	}
	cout<<ans<<endl;			
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