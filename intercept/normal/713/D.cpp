#include<bits/stdc++.h>
using namespace std;
const int M=1001;
int n,m,q,t;
int s[M];
int a[M][M],b[M][M],c[M][M],f[M][M][10][10];
int ask(int lx,int ly,int rx,int ry){
	int l=log2(rx-lx+1),r=log2(ry-ly+1);
	return max({f[lx][ly][l][r],f[rx-(1<<l)+1][ly][l][r],f[lx][ry-(1<<r)+1][l][r],f[rx-(1<<l)+1][ry-(1<<r)+1 ][l][r]});
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
			b[i][j]=a[i][j]?b[i-1][j]+1:0;
			c[i][j]=a[i][j]?c[i][j-1]+1:0;
			f[i][j][0][0]=min({f[i-1][j-1][0][0]+1,b[i][j],c[i][j]});
		}
	}
	for(int l=1;l<10;++l){
		for(int i=1;i+(1<<l)-1<=n;++i){
			for(int j=1;j<=m;++j){
				f[i][j][l][0]=max(f[i][j][l-1][0],f[i+(1<<l-1)][j][l-1][0]);
			}
		}
	}
	for(int l=0;l<10;++l){
		for(int r=1;r<10;++r){
			for(int i=1;i+(1<<l)-1<=n;++i){
				for(int j=1;j+(1<<r)-1<=m;++j){
					f[i][j][l][r]=max(f[i][j][l][r-1],f[i][j+(1<<r-1)][l][r-1]);
				}
			}
		}
	}
	scanf("%d",&q);
	for(int i=1,lx,ly,rx,ry;i<=q;++i){
		scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
		int l=1,r=min(rx-lx+1,ry-ly+1);
		while(l<=r){
			int mid=l+r>>1;
			if(ask(lx+mid-1,ly+mid-1,rx,ry)>=mid)l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",r);
	}
	return 0;
}