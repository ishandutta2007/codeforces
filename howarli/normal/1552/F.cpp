#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define NX(q) ((q)&(-(q)))
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=200500,INF=1e9+7,mo=998244353;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rand_num(seed);  // 
int RD(int q){return rand_num()%q;}


int n,m,ans;
int a[N][3];
int as[N];
LL f[N];

LL tr[N];
void ADD(int q,int e)
{
	for(;q<=n;q+=NX(q))tr[q]=(tr[q]+e)%mo;
}
LL find(int q)
{
	LL ans=0;
	for(;q;q-=NX(q))ans=(ans+tr[q])%mo;
	return ans;
}
int main()
{
	int q,w,_;
	read(n);

	fo(i,1,n)
	{
		as[i]=read(a[i][0]),read(a[i][1]),read(a[i][2]);
	}
	LL sum=0;
	fo(i,1,n)
	{
		q=lower_bound(as+1,as+1+i,a[i][1])-as;
		f[i]=(sum-find(q-1)+a[i][0]-a[i][1])%mo;
		ADD(i,f[i]);
		sum=(sum+f[i])%mo;

		// printf("%d %lld\n",i,f[i]);
	}



	LL ans=a[n][0]+1;

	fo(i,1,n)if(a[i][2])ans=(ans+f[i])%mo;
	printf("%lld\n",(ans%mo+mo)%mo);

	return 0;
}