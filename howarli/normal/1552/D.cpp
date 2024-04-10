#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=100500,INF=1e9+7,M=200500;
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

int Hx[M*2];
int a[N],b[N];
int d[N];
void ss(int q,int e,int e1)
{
	if(ans)return;
	if(q>n)
	{
		if(e==e1&&e)ans=1;
		return;
	}
	ss(q+1,e,e1);
	ss(q+1,e+a[q],e1);
	ss(q+1,e,e1+a[q]);
}
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);
		fo(i,1,n)read(a[i]),a[i]=abs(a[i]);
		ans=0;
		fo(i,1,n)if(a[i]==0)
		{
			ans=1;
		}
		if(ans)
		{
			printf("YES\n");
			continue;
		}
		if(n==1)
		{
			printf("NO\n");
			continue;
		}

		ss(1,0,0);
		if(ans)printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}