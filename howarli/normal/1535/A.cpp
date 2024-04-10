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
		int q1,w1;
		read(q),read(q1);
		read(w),read(w1);
		int q0=min(q,q1);
		int w0=min(w,w1);

		if(min(q,q1)>max(w,w1)||max(q,q1)<min(w,w1))printf("NO\n");
		else printf("YES\n");
	}



	return 0;
}