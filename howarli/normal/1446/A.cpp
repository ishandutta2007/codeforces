#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=205000,mo=998244353;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,ans;
int a[N],p[N];
LL m;
bool PX(int q,int w){return a[q]<a[w];}
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n),scanf("%lld",&m);
		fo(i,1,n)read(a[i]),p[i]=i;
		sort(p+1,p+1+n,PX);
		ans=0;
		fo(i,1,n)if(a[i]*2LL>=m&&a[i]<=m)
		{
			printf("1\n");
			printf("%d\n",i);
			ans=-2;
			break;
		}
		if(ans==-2)continue;
		LL q=0;
		fo(i,1,n)
		{
			if(q+a[p[i]]<=m)q+=a[p[i]];
			else {ans=-1;break;}
			ans=i;
			if(q*2LL>=m)break;
		}
		if(q*2LL<m)ans=-1;
		if(ans>0)
		{
			printf("%d\n",ans);
			fo(i,1,ans)printf("%d ",p[i]);
			printf("\n");
		}else printf("-1\n");
	}
	return 0;
}