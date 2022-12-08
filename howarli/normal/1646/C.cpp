#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=1000500,INF=1e9+7;
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
uniform_int_distribution<int> dist(0, 1000000000);
int RD(int q){return rand_num()%q;}


int n,m,ans;

LL jc[N];
LL d[N];
int d1[N];
void ss(int q,LL w,int e)
{
	if(q>m)
	{
		d[++d[0]]=w;
		d1[d[0]]=e;
		return;
	}
	if(jc[q]==2)++q;
	ss(q+1,w,e);
	ss(q+1,w+jc[q],e+1);
}
int cnt(LL q)
{
	int ans=0;
	for(;q;q>>=1)if(q&1)++ans;
	return ans;
}
int main()
{
	int q,w,_;
	m=16;
	jc[0]=1;fo(i,1,m)jc[i]=jc[i-1]*i;
	ss(0,0,0);

	read(_);
	while(_--)
	{
		LL n;
		scanf("%lld",&n);

		int ans=cnt(n);
		fo(i,1,d[0])if(d[i]<=n)
		{
			ans=min(ans,d1[i]+cnt(n-d[i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}