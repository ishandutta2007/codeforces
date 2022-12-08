#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=100500;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
int n,m;
int a[N];


int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);
		fo(i,1,n)read(a[i]);
		printf("%d\n",3*n);
		for(int i=1;i<=n;i+=2)
		{
			printf("2 %d %d\n",i,i+1);a[i+1]=a[i+1]-a[i];
			printf("1 %d %d\n",i,i+1);a[i]=a[i+1]+a[i];
			printf("2 %d %d\n",i,i+1);a[i+1]=a[i+1]-a[i];
			printf("2 %d %d\n",i,i+1);a[i+1]=a[i+1]-a[i];
			printf("1 %d %d\n",i,i+1);a[i]=a[i+1]+a[i];
			printf("2 %d %d\n",i,i+1);a[i+1]=a[i+1]-a[i];
		}
		q=w;
	}



	return 0;
}