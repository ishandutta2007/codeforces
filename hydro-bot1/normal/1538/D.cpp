// Hydro submission #614b2fcb03550f6f2d6d28d9@1632323343448
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
int a,b;
int zhi[50010],top;
int pan[50010];

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	memset(pan,-1,sizeof(pan));
	for(i=2;i<=50000;++i)
		if(pan[i])
		{
			zhi[++top]=i;
			for(j=i*i;j<=50000;j+=i) pan[j]=0;
		}
	t=read();
	while(t--)
	{
		a=read();
		b=read();
		k=read();
		if(k==1)
		{
			if(a!=b&&(a%b==0||b%a==0)) printf("YES\n");
			else printf("NO\n");
			continue;
		}
		for(i=1,j=0;i<=top;++i)
		{
			while(a%zhi[i]==0) a/=zhi[i],++j;
			while(b%zhi[i]==0) b/=zhi[i],++j;
		}
		if(a!=1) ++j;
		if(b!=1) ++j;
//		printf("%lld ",j);
		if(j>=k) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}