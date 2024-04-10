#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=200500,mo=998244353;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
struct qqww
{
	int v,i;
}b[N],a[N];
bool PX(qqww q,qqww w){return q.v<w.v;}
int main()
{
	int q,w;
	read(n);
	fo(i,1,n)read(a[i].v),a[i].i=i;
	sort(a+1,a+1+n,PX);
	m=1;
	int b0=0;
	fo(i,2,n)
	{
		if(a[m].v==a[i].v)
		{
			b[++b0]=a[i];
			b[++b0]=a[m];
			--m;
		}else a[++m]=a[i];
	}
	if(m==0)
	{
		a[1]=b[b0];
		a[2]=b[b0-1];
		b0-=2;m=2;
	}

	if(m%2==0)
	{
		q=0;
		fo(i,1,m)q^=a[i].v;
		if(q!=0)
		{
			printf("NO\n");
			return 0;
		}
		--m;
	}

	printf("YES\n");
	printf("%d\n",(m-1)/2+max(0,(m-3)/2)+b0/2);
	fo(i,3,m)printf("%d %d %d\n",a[i-2].i,a[i-1].i,a[i].i),++i;
	fo(i,2,m-2)
	{
		printf("%d %d %d\n",a[i].i,a[i-1].i,a[m].i);
		++i;
	}
	fo(i,2,b0)printf("%d %d %d\n",a[1].i,b[i].i,b[i-1].i),++i;
	return 0;
}