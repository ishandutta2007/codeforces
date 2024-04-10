// Hydro submission #6144a8c84b273f753cd4ecec@1631889608333
#include<bits/stdc++.h>
using namespace std;
//#define int long long
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
char s1[100010],s2[100010],a[100010];

int check(int x)
{
	if(s1[x]=='1'&&s2[x]=='1') return 1;
	return 0;
}

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s%s",s1+1,s2+1);
		for(i=1;i<=n;++i) a[i]=0;
		for(i=1,j=k=0;i<=n;++i)
		{
			if(s1[i]!=s2[i]) k+=2,j=0;
			else if(s1[i]=='0')
			{
				if(!a[i-1]&&check(i-1))
					k+=2,a[i-1]=1;
				else if(!a[i+1]&&check(i+1))
					k+=2,a[i+1]=1;
				else ++k;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}