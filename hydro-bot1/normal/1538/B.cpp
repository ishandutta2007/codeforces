// Hydro submission #614b2f78de83b96f5ecfd64b@1632323327652
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
int a[200010];
int sum,num;
int mid;

bool cmp(int x,int y) {return x>y;}

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	t=read();
	while(t--)
	{
		n=read();
		for(i=1,sum=0;i<=n;++i)
			a[i]=read(),sum+=a[i];
		mid=sum/n;
		if(mid*n!=sum){printf("-1\n");continue;}
		for(i=1,k=0;i<=n;++i) if(a[i]>mid) ++k;
		printf("%d\n",k);
	}
	return 0;
}