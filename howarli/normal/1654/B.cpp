#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=200500,INF=1e9+7;
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


int n,m;
char a[N];
int z[300],TI;
int main()
{
	int q,w,_;
	read(_);
	int __=_;
	while(_--)
	{
		scanf("%s",a+1);
		n=strlen(a+1);

		fo(i,1,n)
		{
			z[a[i]]=i;
		}
		q=n;
		fo(i,'a','z')if(z[i])q=min(q,z[i]);
		printf("%s\n",a+q);

		fo(i,1,256)z[i]=0;

	}

	
	return 0;
}