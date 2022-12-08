#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define foi(i,a,b) for(i=a;i<=b;i++)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long LL;
const int N=1e7+5,INF=2147483640;
int n;
LL ans,x,y;
LL f[N*2];
int d[N],S;
LL min(LL q,LL w){return q<w?q:w;}
int main()
{
	int q,w;
	scanf("%d%I64d%I64d",&n,&x,&y);
	memset(f,127,sizeof(f));
	f[1]=x;S=1;f[2]=x+y;
	q=n;n*=2;
	fo(i,2,n)
	{
		while(S<=d[0]&&d[S]<=i)S++;
		f[i]=min(f[i],f[i-1]+x);
		if(S<=d[0])f[i]=min(f[i],f[d[S]]+x*(d[S]-i));
		if(i*2<=n)
		{
			f[i*2]=min(f[i*2],f[i]+y);
			while(S<=d[0]&&f[d[d[0]]]+x*(d[d[0]]-i)>=f[i*2]+x*i)d[0]--;
			d[++d[0]]=i*2;
		}
	}
	printf("%I64d\n", f[q]);
	return 0;
}