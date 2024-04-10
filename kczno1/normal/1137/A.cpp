#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=1000+5;
int a[2][N][N],x[2][N][N],y[2][N][N];

int q[N];
void work(int a[N][N],int x[N][N],int y[N][N],int n,int m)
{
	rep(i,1,n)
	{
		rep(j,1,m)q[j]=a[i][j];
		sort(q+1,q+m+1);
		int u=unique(q+1,q+m+1)-q-1;
		rep(j,1,m)
		{
			int k=lower_bound(q+1,q+u+1,a[i][j])-q;
			x[i][j]=k-1;
			y[i][j]=u-k;
		}
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	rep(i,1,n)
	rep(j,1,m)a[0][i][j]=a[1][j][i]=read();
	work(a[0],x[0],y[0],n,m);
	work(a[1],x[1],y[1],m,n);
	rep(i,1,n)
	rep(j,1,m)
	printf("%d%c",max(x[0][i][j],x[1][j][i])+1+max(y[0][i][j],y[1][j][i])," \n"[j==m]);
}