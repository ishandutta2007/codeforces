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
int RD(int q){return rand_num()%q;}


int n,m,ans;
int a[N],b[N];
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);
		char ch=' ';
		for(;ch<'a'||ch>'z';ch=getchar());
		fo(i,1,n)
		{
			b[i]=a[i]=ch;
			ch=getchar();
		}
		sort(a+1,a+1+n);
		int ans=0;
		fo(i,1,n)if(a[i]!=b[i])++ans;
		printf("%d\n",ans);
	}	
	return 0;
}