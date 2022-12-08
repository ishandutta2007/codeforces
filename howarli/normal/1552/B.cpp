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


int n,m,nw;
int a[N][6];
bool CEK(int q)
{
	fo(i,1,n)
	{
		int w=0;
		fo(j,1,5)if(a[i][j]>=a[q][j])++w;
		if(w<3)return 0;
	}
	return 1;
}
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);
		int ans=-1;
		q=1;
		fo(i,1,n)
		{
			w=0;
			fo(j,1,5)
			{
				read(a[i][j]);
				if(a[i][j]>=a[q][j])++w;
			}
			if(w<3)
			{
				q=i;
			}
		}
		if(CEK(q))ans=q;

		printf("%d\n",ans);
	}	
	return 0;
}