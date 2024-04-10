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
		a[0]=0;
		fo(i,1,n)
		{
			int nw;
			read(nw);
			if(nw==1)
			{
				a[++a[0]]=1;
			}else{
				for(;a[a[0]]+1!=nw;--a[0]);
				++a[a[0]];
			}

			printf("%d",a[1]);
			fo(i,2,a[0])printf(".%d",a[i]);
			printf("\n");
		}
	}



	return 0;
}