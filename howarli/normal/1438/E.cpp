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
int n,m,ans;
LL a[N],f[N];
struct qqww
{
	int i;
	LL v;
}b[N];
bool PX(qqww q,qqww w){return q.v>w.v;}
void divide(int l,int r)
{
	if(r-l<2)return;
	int mid=(l+r)>>1;
	int m=0;
	fo(i,mid+1,r)b[++m].i=i,b[m].v=a[i]-(f[i-1]-f[mid]);
	sort(b+1,b+1+m,PX);
	fo(i,l,mid)
	{
		LL t=a[i]-(f[mid]-f[i]);
		for(int j=1;j<=m&&b[j].v+t>=0;++j)
		{
			int q=b[j].i;
			if((a[i]^a[q])==f[q-1]-f[i]&&q-i>1)
			{
				++ans;
			}
		}
	}
	divide(l,mid);	
	divide(mid+1,r);
}
int main()
{
	int q,w;
	read(n);
	fo(i,1,n)f[i]=f[i-1]+(a[i]=read(q));
	divide(1,n);
	printf("%d\n",ans);
	return 0;
}