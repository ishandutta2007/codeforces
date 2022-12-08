#include <bits/stdc++.h>
#define fo(i,a,b)  for(int i=a;i<=b;++i)
#define fod(i,a,b)  for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=10050,mo=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
int Ans[N];
int main()
{
	// freopen("!.in","r",stdin);
	// freopen("1.out","w",stdout);
	int q,w,_;
	// int SRT=clock();
	read(n);
	q=1;
	fo(i,2,n)
	{
		w=i;
		printf("? %d %d\n",q,w);fflush(stdout);
		int k1,k2;
		read(k1);
		printf("? %d %d\n",w,q);fflush(stdout);
		read(k2);
		if(k1>k2)
		{
			Ans[q]=k1;q=w;
		}else Ans[w]=k2;
	}
	Ans[q]=n;
	printf("!\n");
	fo(i,1,n)printf("%d ",Ans[i]);
	fflush(stdout);
	return 0;
}