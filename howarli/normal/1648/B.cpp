// #define __AVX__ 1
// #define __AVX2__ 1
// #define __SSE__ 1
// #define __SSE2__ 1
// #define __SSE2_MATH__ 1
// #define __SSE3__ 1
// #define __SSE4_1__ 1
// #define __SSE4_2__ 1
// #define __SSE_MATH__ 1
// #define __SSSE3__ 1
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

#define S 100000
char bf[S],*p1=bf,*p2=bf;
#define nc() (p1==p2&&(p2=(p1=bf)+fread(bf,1,S,stdin),p2==p1)?-1:*p1++)


using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=1000500,INF=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=nc());
	if(ch=='-')ch=nc(),q=1;
	for(;ch>='0'&&ch<='9';ch=nc())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rand_num(seed);  // 
uniform_int_distribution<int> dist(0, 1000000000);
int RD(int q){return rand_num()%q;}


int n,m,ans;
int a[N];
int f[N];
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n),read(m);
		// fo(i,1,n)a[i]=i;
		fo(i,1,n)read(a[i]);
		sort(a+1,a+1+n);
		n=unique(a+1,a+1+n)-a-1;

		fo(i,1,n)++f[a[i]];
		fo(i,1,m)f[i]+=f[i-1];

		bool OK=1;
		if(a[1]!=1)
		{
			OK=0;
		}

		fo(i,1,n)
		{
			q=a[i];
			if(!OK)break;
			for(int j=q,cnt=1;j<=m;j+=q,++cnt)if(f[cnt]-f[cnt-1]==0)
			{
				if(f[min(m,j+q-1)]-f[j-1])OK=0;
			}
		}

		if(OK)puts("Yes");
			else puts("No");
		fo(i,0,m)f[i]=0;
	}
	return 0;
}