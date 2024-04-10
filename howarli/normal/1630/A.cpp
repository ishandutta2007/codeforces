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
int a[N],b[N];
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n),read(m);
		int sum=0;
		if(m==n-1)
		{
			if(n<=4)
			{
				printf("-1\n");
				continue;
			}

			
			printf("%d %d\n",n-1,m-2);
			printf("%d %d\n",n-2,2);
			printf("%d %d\n",1,0);
			
			fo(i,3,n-3)if(i!=m && n-i-1!=m)
			{
				q=n-i-1;
				if(q>i)printf("%d %d\n",q,i);
			}

			continue;
		}
		q=w=-1;
		
		
		printf("%d %d\n",n-1,m);
		
		fo(i,1,n-2)if(i!=m && n-i-1!=m)
		{
			q=n-i-1;
			if(q<i)printf("%d %d\n",q,i);
		}else if(n-i-1==m)printf("%d %d\n",0,i);
	}

	
	return 0;
}