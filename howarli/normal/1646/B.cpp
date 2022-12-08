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
int a[N];
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);
		fo(i,1,n)read(a[i]);
		sort(a+1,a+1+n);

		LL sum1=0,sum0=0;
		bool OK=0;
		q=1;
		sum1=a[1];
		fod(i,n,1)
		{
			sum0+=a[i];
			sum1+=a[++q];
			if(q>=i)break;
			if(sum0>sum1)
			{
				OK=1;
				break;
			}
		}
		if(OK)puts("YES");
			else puts("NO");
	}

	
	return 0;
}