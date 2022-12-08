#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=400500;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
int n,m;
int a[N][100];
int f[N],b[N];
int er[N],cnt[N];
int Ans[N];
int main()
{

	int STR=clock();
	int q,w,qq;
	er[0]=1;fo(i,1,20)er[i]=er[i-1]<<1;
	read(n),read(qq),read(q);
	fo(i,1,n)
	{
		char ch=' ';
		for(;ch<'0'||ch>'9';ch=getchar());
		fo(j,1,qq)a[i][j]=ch-48,ch=getchar();
	}
	fo(i,1,er[17])
	{
		cnt[i]=cnt[i>>1]+(i&1);
	}

	srand(19260817);
	fod(i,rand()%1000,0)q=rand();
	int ans=0;
	fo(I,1,100)
	{
		int nw=(rand()*rand()+rand())%n+1;
		int mx=0;
		fo(i,1,n)
		{
			q=b[i]=0;
			fo(j,1,qq)if(a[nw][j])
			{
				if(a[i][j])b[i]+=er[q];
				++q;
			}
			mx=max(mx,b[i]);
			++f[b[i]];
		}

		fo(i,1,mx)
		{
			for(int k=(i-1)&i;k;k=(k-1)&i)
			{
				f[k]+=f[i];
			}
		}
		// printf("%d\n",mx);
		fo(i,1,mx)
		{
			if(f[i]>=(n+1)/2 && cnt[i]>ans)
			{
				ans=cnt[i];
				q=0;
				fo(j,1,qq)Ans[j]=0;
				fo(j,1,qq)if(a[nw][j])
				{
					if(i&er[q])Ans[j]=1;
					++q;
				}
			}
			f[i]=0;
		}
		if(clock()-STR>2500)break;
	}
	// printf("%d\n",ans);
	fo(i,1,qq)printf("%d",Ans[i]);printf("\n");

	return 0;
}