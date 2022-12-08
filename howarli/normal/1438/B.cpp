#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=205000,mo=998244353;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
map<int,int>Hx;
int main()
{
	int q,w,_;
	int TI=0;
	read(_);
	while(_--)
	{
		read(n);
		bool OK=1;
		++TI;
		fo(i,1,n)
		{
			read(q);
			if(Hx[q]==TI)OK=0;
			Hx[q]=TI;
		}
		if(!OK)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}