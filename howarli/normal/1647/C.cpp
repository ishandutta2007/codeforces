#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=1500,INF=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rand_num(seed);  // 
uniform_int_distribution<int> dist(0, 1000000000);
int RD(int q){return rand_num()%q;}


int n,m,ans;
char a[N][N];
int Ans[N*N][4];
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);read(m);
		fo(i,1,n)
		{
			scanf("%s",a[i]+1);
		}

		ans=0;
		fod(i,n,1)
		{
			fod(j,m,2)if(a[i][j]=='1')
			{
				++ans;
				Ans[ans][0]=i;
				Ans[ans][1]=j-1;
				Ans[ans][2]=i;
				Ans[ans][3]=j;
			}
			if(a[i][1]=='1')
			{
				if(i==1){ans=-10;break;}
				++ans;
				Ans[ans][0]=i-1;
				Ans[ans][1]=1;
				Ans[ans][2]=i;
				Ans[ans][3]=1;
			}

		}
		if(ans>=0)
		{
			printf("%d\n",ans);
			fo(i,1,ans)printf("%d %d %d %d\n",Ans[i][0],Ans[i][1],Ans[i][2],Ans[i][3]);

		}else puts("-1");

		
	}
	
	return 0;
}