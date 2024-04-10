#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=5000+5;
int a[N][N];
int mx[N][N];

int main()
{
//	freopen("1.in","r",stdin);
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d",a[1]+i);
	rep(i,2,n)
	rep(j,1,n-i+1)a[i][j]=a[i-1][j]^a[i-1][j+1];
	rep(i,1,n)
	rep(j,i,n)mx[i][j]=max(a[j-i+1][i],mx[i][j-1]);
	per(i,n,1)
	rep(j,i,n)chmax(mx[i][j],mx[i+1][j]);
	int m;
	cin>>m;
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",mx[l][r]);
	}
}