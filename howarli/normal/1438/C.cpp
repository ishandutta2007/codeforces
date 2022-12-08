#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=200,mo=998244353;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
int a[N][N],b[N][N];
int main()
{
	int q,w,_;
	int TI=0;
	read(_);
	while(_--)
	{
		read(n);read(m);
		fo(i,1,n)fo(j,1,m)b[i][j]=1;
		fo(i,1,n)fo(j,1,m)
		{
			read(a[i][j]);
			if((i+j)%2!=a[i][j]%2)++a[i][j];
		}

		fo(i,1,n)
		{
			fo(j,1,m)printf("%d ",a[i][j]);
			printf("\n");
		}
		fo(i,1,n)fo(j,1,m)a[i][j]=0,b[i][j]=1;
	}
	return 0;
}