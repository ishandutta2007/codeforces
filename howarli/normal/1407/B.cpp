#include <bits/stdc++.h>
#define fo(i,a,b)  for(int i=a;i<=b;++i)
#define fod(i,a,b)  for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=2050,mo=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
int a[N];
bool PX(int q,int w){return q>w;}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
	int q,w,_;
	// int SRT=clock();
	int Li=11000;
	read(_);
	fo(II,1,_) 
	{
		read(n);
		fo(i,1,n)read(a[i]);
		sort(a+1,a+1+n,PX);
		m=n-1;
		int nw=a[1];
		printf("%d",a[1]);
		fo(i,2,n)if(a[i]==a[1])printf(" %d",a[i]),a[i]=0,--m;
		a[1]=0;
		while(m)
		{
			int mx,mx1=-1;
			fo(i,1,n)if(a[i])
			{
				q=gcd(a[i],nw);
				if(q>mx1)mx1=q,mx=i;
			}
			printf(" %d",a[mx]);
			fo(i,mx+1,n)if(a[i]==a[mx])printf(" %d",a[mx]),a[i]=0,--m;
			--m;
			a[mx]=0;
			nw=mx1;
			if(nw==1)
			{
				fo(i,1,n)if(a[i])printf(" %d",a[i]),a[i]=0,--m;
			}
		}
		printf("\n");
	}
	
	return 0;
}