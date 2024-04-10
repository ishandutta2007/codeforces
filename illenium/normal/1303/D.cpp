#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],x[maxn],cnt[maxn];

inline ll X(ll x)
{
	int cnt=-1;
	while(x) x>>=1,cnt++;
	return cnt;
}

int main()
{
	int T=read();
	while(T--)
	{
		ll n=read(),m=read(),ans=0;
		for(int i=0;i<=62;i++) cnt[i]=0;
		for(int i=1;i<=m;i++) a[i]=read(),x[i]=X(a[i]),cnt[x[i]]++;
		//for(int i=0;i<=10;i++) cout<<i<<" "<<cnt[i]<<endl; cout<<endl;
		int ff=0;
		for(ll i=0;i<=63;i++)
		{
			if(n%2==1)
			{
				if(cnt[i]==0)
				{
					int f=0;
					for(ll j=i+1;j<=63;j++)
						if(cnt[j])
						{
							cnt[j]--,ans+=j-i,f=1;
							for(int k=j-1;k>=i;k--) cnt[k]++; 
							break;
						}
					if(f==0) ff=1;
				}
				else cnt[i]--;
			}
			cnt[i+1]+=cnt[i]/2; n>>=1ll;
			//cout<<i<<" "<<ff<<" "<<cnt[3]<<endl;
		}
		if(ff==1) puts("-1");
		else cout<<ans<<endl;
	}
	return 0;
}