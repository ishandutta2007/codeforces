#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
void chmax(int &x,int y) { if(x<y)x=y; }
void chmin(int &x,int y) { if(x>y)x=y; }
const int N=100+5;
int n,m,a[N][N];
int cnt_row[N],cnt_col[N];

int k;
void check_row()
{
	rep(i,1,n)
	{
		int x=a[i][1];
	  rep(j,2,m) chmin(x,a[i][j]);
	    k+=x;cnt_row[i]=x;
	    rep(j,1,m) a[i][j]-=x;
	}
}
void check_col()
{
	rep(j,1,m)
	{
		int x=a[1][j];
	  rep(i,2,n) chmin(x,a[i][j]);
	    k+=x;cnt_col[j]=x;
	    rep(i,1,n) a[i][j]-=x;
	}
}

int main()
{
	cin>>n>>m;
	rep(i,1,n)
	rep(j,1,m)
	 scanf("%d",a[i]+j);
	 
	if(n<=m) {check_row();check_col();}
	else {check_col();check_row();}
	
	rep(i,1,n)
	rep(j,1,m)
	if(a[i][j]){puts("-1");exit(0);}
	
	printf("%d\n",k);
	rep(i,1,n)
	while(cnt_row[i]--) printf("row %d\n",i);
	rep(j,1,m)
	while(cnt_col[j]--) printf("col %d\n",j);
}