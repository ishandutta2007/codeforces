#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=100500,INF=1e9+7;
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

bool Miller_Rabin(LL n) {
	if(n==1)return 1;
	if(n==2)return 1;
	if(n%2==0)return 0;
	for(LL q=3;q*q<=n;q+=2)if(n%q==0)return 0;
	return 1;
}

int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n),read(m);
		int c=0;
		for(;n%m==0;++c,n/=m);

		if(c<2)
		{
			puts("NO");
			continue;
		}
		if(!Miller_Rabin(n))
		{
			puts("YES");
			continue;
		}
		if(Miller_Rabin(m))
		{
			puts("NO");
		}
		else if(c>=4)
		{
			puts("YES");
		}
		else if(c<=2)
		{
			puts("NO");
		}
		else 
		{
			q=sqrt(m)+1e-6;
			if(q*q==m && q==n)
			{
				puts("NO");
			}else puts("YES");
		}
	}

	
	return 0;
}