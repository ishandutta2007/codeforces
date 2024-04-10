#include <cstdio>

int map[2501][2501],n,m,k,up[10],down[10];
long long ans;
int calc(int x1,int y1,int x2,int y2){return map[x2][y2]-map[x1-1][y2]-map[x2][y1-1]+map[x1-1][y1-1];}
int getcell(int x,int y){return map[x][y]-map[x-1][y]-map[x][y-1]+map[x-1][y-1];}
int abs(int x){return (x<0)?(-x):x;}
void solve(int x,int y,int lx,int ly){
	if(!lx||!ly)return;
	if(lx<=ly){
		int mid=(ly>>1);
		solve(x,y,lx,mid);
		solve(x,y+mid+1,lx,ly-mid-1);
		int tem=ans;
		for(int i=x;i<x+lx;i++){
			for(int j=0;j<=k;j++)
				up[j]=y+ly-1,down[j]=y;
			int contain=0;
			for(int j=i;j<x+lx;j++){
				contain+=getcell(j,y+mid);
				if(contain>k)break;
//				printf("%d\n",contain);
				for(int l=0;l<=k;l++){
					while(calc(i,y+mid+1,j,up[l])>l)--up[l];
					while(calc(i,down[l],j,y+mid-1)>l)++down[l];
//					printf("%d %d %d %d %d\n",i,j,l,up[l],down[l]);
				}
				for(int l=0;l<=k;l++){
					if(k-contain-l>=0)ans+=abs(up[l]-(l?up[l-1]:(y+mid)))*abs(((k-contain-l>0)?down[k-contain-l-1]:(y+mid))-down[k-contain-l]);
				}
				ans+=abs(((k-contain)?up[k-contain-1]:(y+mid))-up[k-contain]);
				ans+=abs(((k-contain)?down[k-contain-1]:(y+mid))-down[k-contain]);
				if(contain==k)++ans;
//			printf("@#$ %d\n",ans-tem);
			}
		}
//		printf("^%d %d %d %d %d\n",x,y,lx,ly,ans-tem);
	}
	else{
		int mid=(lx>>1);
		solve(x,y,mid,ly);
		solve(x+mid+1,y,lx-mid-1,ly);
		int tem=ans;
		for(int i=y;i<y+ly;i++){
			for(int j=0;j<=k;j++)
				up[j]=x+lx-1,down[j]=x;
			int contain=0;
			for(int j=i;j<y+ly;j++){
				contain+=getcell(x+mid,j);
				if(contain>k)break;
				for(int l=0;l<=k;l++){
					while(calc(x+mid+1,i,up[l],j)>l)--up[l];
					while(calc(down[l],i,x+mid-1,j)>l)++down[l];
				}
				for(int l=0;l<=k;l++){
					if(k-contain-l>=0)ans+=abs(up[l]-(l?up[l-1]:(x+mid)))*abs(((k-contain-l)?down[k-contain-l-1]:(x+mid))-down[k-contain-l]);
				}
				ans+=abs(((k-contain)?up[k-contain-1]:(x+mid))-up[k-contain]);
				ans+=abs(((k-contain)?down[k-contain-1]:(x+mid))-down[k-contain]);
				if(contain==k)++ans;
			}
		}
//		printf("*%d %d %d %d %d\n",x,y,lx,ly,ans-tem);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&map[i][j]),map[i][j]+=map[i][j-1]+map[i-1][j]-map[i-1][j-1];
	solve(1,1,n,m);
	printf("%I64d",ans);
}