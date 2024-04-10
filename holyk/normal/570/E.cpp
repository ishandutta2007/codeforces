#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int M=1e9+7;
int n,m,f[2][505][505];
char a[505][505];
template<typename T>
inline void inc(T&x,const T&y){x+=y;if(x>=M)x-=M;}
int main(){
	scanf("%d%d",&n,&m);
	REP(i,1,n)scanf("%s",a[i]+1);
	if(a[1][1]!=a[n][m])return puts("0"),0;
	int now=0;f[0][1][n]=1;
	REP(p,2,n+m>>1){
		now^=1;
	//	REP(i,1,n)REP(j,1,m)f[now][i][j]=0;
		memset(f[now],0,sizeof f[now]);
		REP(x1,1,min(p,n)){
			int y1=p-x1+1;
			for(int x2=n;n-x2+1<=min(p,n);--x2){
				int y2=m+n-p-x2+1;//printf("ext %d %d %d %d\n",x1,y1,x2,y2);
				if(a[x1][y1]==a[x2][y2]){
					inc(f[now][x1][x2],f[now^1][x1-1][x2+1]);
					inc(f[now][x1][x2],f[now^1][x1-1][x2]);
					inc(f[now][x1][x2],f[now^1][x1][x2+1]);
					inc(f[now][x1][x2],f[now^1][x1][x2]);
				}
			}
		}
	//	REP(i,1,n)for(int j=n;j;--j){
		//	printf("%d:%d %d %d %d -- %d\n",p,i,p-i+1,j,m+n-p-j+1,f[now][i][j]);
	//	}
	}
	int ans=0;
	REP(i,1,n)inc(ans,f[now][i][i]);
	if(n+m&1)REP(i,1,n-1)inc(ans,f[now][i][i+1]);
	cout<<ans%M;
	return 0;
}
//f[step][x1][x2]