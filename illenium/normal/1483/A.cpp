#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <int> v[maxn],ans;
int n,m,cnt[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); rep(i,1,m) v[i].clear(); rep(i,1,n) cnt[i]=0; ans.clear();
		rep(i,1,m)
		{
			int k=read();
			rep(j,1,k) {int x=read(); v[i].pb(x); cnt[x]++;}
		}
		int mx=0,f=0;
		rep(i,1,n) if(mx<cnt[i]) mx=cnt[i],f=i;
		
		int up=(m+1)/2,cnt=0,FF=0;
		rep(i,1,m)
		{
			int F=0;
			for(int j=0;j<v[i].size();j++)
			{
				if(v[i][j]==f)
				{
					F=1;
					if(v[i].size()==1||(cnt+mx<=up)) ans.pb(f),cnt++;
					else if(j!=0) ans.pb(v[i][j-1]);
					else ans.pb(v[i][j+1]);
					mx--; break;
				}
			}
			if(!F) ans.pb(v[i][0]);
		}
		if(cnt>up) puts("NO");
		else
		{
			puts("YES");
			for(int i=0;i<ans.size();i++) printf("%d ",ans[i]); puts("");
		}
	}
	return 0;
}