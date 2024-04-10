#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=200+5,K=200+5,Q=5000+5;
int k,ans[N][N];
namespace BIPATITE
{
const int N=::N*::N+5;
int lk[2][N][K];
int get_mex(bool d,int x)
{
	int i=1;
	while(lk[d][x][i])++i;
	return i;
}
void add_e(int x,int y,int c)
{
	lk[0][x][c]=y;
	lk[1][y][c]=x;
	ans[x/::N][y/::N]=c;
}
void modify(bool d,int x,int c0,int c1)
{
	if(!lk[d][x][c0])return ;
	int y=lk[d][x][c0];
	lk[d][x][c0]=0;
	lk[d^1][y][c0]=0;
	modify(d^1,y,c1,c0);
	if(!d)add_e(x,y,c1);
	else add_e(y,x,c1);
}
void add_e(int x,int y)
{
	int lx=get_mex(0,x),ly=get_mex(1,y);	
	if(!lk[1][y][lx]){add_e(x,y,lx);return ;} 
	if(!lk[0][x][ly]){add_e(x,y,ly);return ;} 
	modify(1,y,lx,ly);
	add_e(x,y,lx);
}
};
int du[2][N];
int inc(bool d,int x)
{
	return x*N+(du[d][x]++)/k;	
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	int n,m,q;
	cin>>n>>m>>q>>k;
	static pii e[Q];
	rep(i,1,q)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int x1=inc(0,x),y1=inc(1,y);
		BIPATITE::add_e(x1,y1);
		e[i]={x,y};
	}
	int ans1=0;
	rep(x,1,n)ans1+=du[0][x]%k>0;
	rep(x,1,m)ans1+=du[1][x]%k>0;
	printf("%d\n",ans1);
	rep(i,1,q)printf("%d ",ans[e[i].first][e[i].second]);
}