#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=1500,INF=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
int z[N],TI,z1[N];

int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		++TI;
		read(n);
		fo(i,1,n)
		{
			read(q);
			++z[q];
		}
		ans=0;
		q=2;
		fo(i,0,n)if(z[i]<q)
		{
			if(z[i])
			{
				ans+=i;
				--q;
			}else ans+=i*q,q=0;
			if(!q)break;
		}
		printf("%d\n",ans);
		fo(i,0,100)z[i]=0;
	}
	return 0;
}