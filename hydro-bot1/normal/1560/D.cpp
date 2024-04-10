// Hydro submission #6129e5abe0874e17dc497ea8@1630135723422
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,i,j,k,t;
char c[200][200];
char s[200];
int now,ans;

int wei(int x)
{
	int ans=0;
	while(x)
	{
		++ans;
		x/=10;
	}
	return ans;
}

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	c[0][1]='0';
	c[0][0]=1;
	for(i=1,m=1;i<=10000000000000000;i<<=1,++m)
	{
		t=wei(i);
		k=i;
		while(k)
		{
			c[m][t--]=k%10+'0';
			k/=10;
		}
		c[m][0]=strlen(c[m]+1);
//		printf("%s\n",c[m]+1);
	}
	t=read();
	while(t--)
	{
		ans=0x7fffffff;	
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i=1;i<m;++i)
		{
			now=0;
			for(j=1,k=1;j<=c[i][0]&&k<=n;++j)
			{
				while(k<=n&&s[k]!=c[i][j])++k,++now;
				if(k>n) break;
				if(s[k]==c[i][j]) ++k;
			}
			if(j<=c[i][0])
				now+=(c[i][0]-j+1);
			else if(n-k>=0)
				now+=(n-k+1);
			ans=min(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}