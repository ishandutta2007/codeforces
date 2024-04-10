#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <int> mp[maxn];
int v1[maxn],v2[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),ans=0;
		for(int i=1;i<=n;i++)
		{
			int x=read();
			for(int j=1;j<=x;j++)
			{
				int u=read();
				mp[i].push_back(u);
			}
			sort(mp[i].begin(),mp[i].end());
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<mp[i].size();j++)
			{
				if(v2[mp[i][j]]==0)
				{
					v1[i]=1;
					v2[mp[i][j]]=1;
					ans++; break;
				}
			}
		}
		
		if(ans==n) puts("OPTIMAL");
		else
		{
			puts("IMPROVE");
			int f1=0,f2=0;
			for(int i=1;i<=n;i++) if(v1[i]==0) {f1=i; break;}
			for(int i=1;i<=n;i++) if(v2[i]==0) {f2=i; break;}
			printf("%d %d\n",f1,f2);
		}
		for(int i=1;i<=n;i++) mp[i].clear(),v1[i]=0,v2[i]=0;
	}
	return 0;
}