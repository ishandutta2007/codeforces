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

int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);
		q=0;
		fo(i,1,n)
		{
			read(a[i]);
		}
		// sort(a+1,a+1+n);
		int ans=0;
		fo(i,1,n)
		{
			fo(j,1,i-1)if(gcd(a[i],a[j])>1 || (a[i]%2==0)||(a[j]%2==0))++ans;
		}
		printf("%d\n",ans);
	}



	return 0;
}