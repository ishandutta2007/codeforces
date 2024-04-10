#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1005,mo=1e9+7;
const ll inf=2e18;
int n,m,t;
int d[N*N][2],ds;
int fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
ll p,fi[N][N];
char a[N][N];
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d%d\n",&n,&m,&t);
	fo(i,1,n){
		fo(j,1,m)a[i][j]=getchar();
		scanf("\n");
	}
	fo(i,1,n)fo(j,1,m)fi[i][j]=inf;
	fo(i,1,n)fo(j,1,m)if(a[i][j]==a[i+1][j]||a[i][j]==a[i-1][j]||a[i][j]==a[i][j+1]||a[i][j]==a[i][j-1]){
		d[++ds][0]=i;d[ds][1]=j;
		fi[i][j]=0;
	}
	for(int i=1;i<=ds;++i){
		int x=d[i][0],y=d[i][1];
		fo(k,0,3){
			int xx=x+fx[k][0],yy=y+fx[k][1];
			if(xx&&yy&&xx<=n&&yy<=m&&fi[xx][yy]==inf){
				fi[xx][yy]=fi[x][y]+1;
				d[++ds][0]=xx;
				d[ds][1]=yy;
			}
		}
	}
	int x,y;
	fo(i,1,t){
		scanf("%d%d%lld",&x,&y,&p);
		if(p<=fi[x][y])printf("%d\n",a[x][y]-'0');
		else printf("%d\n",(a[x][y]-'0')^((p-fi[x][y])&1));
	}
}