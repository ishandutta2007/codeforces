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


int n,m,ans;
int a[N],p[N];
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		int K;
		read(n),read(K);
		fo(i,1,n)p[i]=read(a[i]);
		sort(p+1,p+1+n);
		int mi=(n-K+1)/2+K;
		int ans=INF;
		int L=0,R=0;

		fo(i,1,n-mi+1)
		{
			if(ans>p[i+mi-1]-p[i])
			{
				ans=p[i+mi-1]-p[i];
				L=p[i];
				R=p[i+mi-1];
			}
		}

		printf("%d %d\n",L,R);
		int la=1;
		q=0;
		fo(i,1,n)
		{
			if(K==1)
			{
				printf("%d %d\n",la,n);
				break;
			}
			if(L<=a[i]&&a[i]<=R)++q;
			else --q;
			if(q>0)
			{
				printf("%d %d\n",la,i);
				la=i+1;
				--K;
				q=0;
			}
		}


	}
	
	return 0;
}