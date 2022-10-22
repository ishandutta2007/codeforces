#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
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

char s[maxn];
int a[maxn],cnt[maxn][10],n;

inline void solve()
{
	for(int i=n;i>=1;i--)
	{
		for(int j=a[i]-1;j>=(i==1);j--)
		{
			int res=0;
			for(int k=0;k<10;k++) res+=cnt[i-1][k]^(k==j);
			if(res<=n-i)
			{
				for(int k=1;k<i;k++) cout<<a[k];
				cout<<j;
				for(int k=1;k<=n-i-res;k++) cout<<"9";
				for(int k=9;k>=0;k--) if(cnt[i-1][k]^(k==j)) cout<<k;
				puts("");
				return;
			}
		}
	}
	for(int i=1;i<=n-2;i++) cout<<"9"; cout<<endl;
}

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int k=0;k<10;k++) cnt[0][k]=0; 
		for(int i=1;i<=n;i++)
		{
			a[i]=s[i]-'0';
			for(int k=0;k<10;k++) cnt[i][k]=cnt[i-1][k]^(k==a[i]);
		}
		solve();
	}
	return 0;
}