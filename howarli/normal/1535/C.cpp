#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=200500;
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
		char ch=' ';
		for(;(ch<'0'||ch>'9')&&ch!='?';ch=getchar());
		for(n=0;(ch<='9'&&ch>='0')||ch=='?';ch=getchar())a[++n]=ch;
		LL ans=0;


		q=0;
		int t=0;
		fo(i,1,n)
		{
			if(a[i]!='?')
			{
				if(q)
				{
					if(a[q]!=a[i] &&(i-q-1)%2)t=q;
					else if(a[q]==a[i] && (i-q-1)%2==0)t=q;
				}
				q=i;
			}
			ans+=i-t;
		}

		printf("%lld\n",ans);
	}



	return 0;
}