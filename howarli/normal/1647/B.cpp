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
int fx[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool z[N][N];
int mxx,mxy,mix,miy,cnt;
void ss(int q,int w)
{
	mxx=max(mxx,q);
	mxy=max(mxy,w);
	mix=min(mix,q);
	miy=min(miy,w);
	++cnt;
	z[q][w]=1;
	fo(i,0,3)
	{
		int q1=q+fx[i][0];
		int w1=w+fx[i][1];

		if(0<q1 && 0<w1 && q1<=n && w1<=m && a[q1][w1]=='1' && !z[q1][w1])ss(q1,w1);
	}
}
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

		bool OK=1;
		fo(i,1,n)fo(j,1,m)if(!z[i][j] && a[i][j]=='1')
		{
			cnt=0;
			mix=mxx=i;
			miy=mxy=j;
			ss(i,j);
			if(cnt!= (mxx-mix+1)*(mxy-miy+1))OK=0;
		}
		if(OK)puts("YES");
		else puts("NO");

		fo(i,0,n)fo(j,0,m)z[i][j]=0;
	}
	
	return 0;
}