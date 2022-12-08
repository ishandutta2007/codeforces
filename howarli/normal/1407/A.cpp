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
int f0[N],f1[N];
map<int,int>Hx,Hx1;
int main()
{
	int q,w,_;
	// int SRT=clock();
	int Li=11000;
	read(_);
	fo(II,1,_) 
	{
		 read(n);
		 w=0;
		 fo(i,1,n)if(read(q)==0)++w;
		 q=n/2;
		 if(w>=q)
		 {
		 	printf("%d\n",q);
		 	fo(i,1,q)printf("0 ");printf("\n");
		 }else{
		 	q=n-w;
		 	if(q&1)--q;
		 	printf("%d\n",q);
		 	fo(i,1,q)printf("1 ");printf("\n");

		 }
	}
	
	return 0;
}