#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[505][505]={{0,0,0,0,0},{0,15,14,13,6},{0,12,8,9,7},{0,11,16,10,5},{0,1,2,3,4}};
int b[505][505],n;

int main()
{
	//freopen("t1.in","r",stdin);
	n=read();
	if(n<=2) {puts("-1"); return 0;}
	if(n==3)
	{
		rep(i,1,3)
		{
			rep(j,1,3) cout<<a[i][j]-7<<" ";
			cout<<endl;
		}
		return 0;
	}
	else if(n==4)
	{
		rep(i,1,4)
		{
			rep(j,1,4) cout<<a[i][j]<<" ";
			cout<<endl;
		}
		return 0;
	}
	int nw=0;
	for(int i=n;i>4;i--)
	{
		if(i%2==1)
		{
			rep(j,1,i) a[j][i]=++nw;
			per(j,i-1,1) a[i][j]=++nw;
		}
		
		else
		{
			rep(j,1,i) a[i][j]=++nw;
			per(j,i-1,1) a[j][i]=++nw;
		}
	}
	rep(i,1,4) rep(j,1,4) a[i][j]=nw+a[i][j];
	rep(i,1,n)
	{
		rep(j,1,n) printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}