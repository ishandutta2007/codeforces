#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1ll<<((x)-1))
int i,j,k,n,m,t,a[66][66];

int ask(int a,int b,int c,int d){
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	scanf("%d",&a);return a;
}

void dfs(int x,int y){
	int i,j,k;
	if(x>n||y>n)return;
	if(x+2<=n&&y<=n&&(a[x+2][y]==-1)){
		k=ask(x,y,x+2,y);
		if(k)a[x+2][y]=a[x][y];
		else a[x+2][y]=1-a[x][y];
		dfs(x+2,y);
	}
	if(x<=n&&y+2<=n&&(a[x][y+2]==-1)){
		k=ask(x,y,x,y+2);
		if(k)a[x][y+2]=a[x][y];
		else a[x][y+2]=1-a[x][y];
		dfs(x,y+2);
	}
	if(x+1<=n&&y+1<=n&&(a[x+1][y+1]==-1)){
		k=ask(x,y,x+1,y+1);
		if(k)a[x+1][y+1]=a[x][y];
		else a[x+1][y+1]=1-a[x][y];
		dfs(x+1,y+1);
	}
}

void dfs2(int x,int y){
	if(a[x][y]==-1)return;
	if(x>n||y>n)return;
	if(x<1||y<1)return;
	
	if(x+2<=n&&y<=n&&(a[x+2][y]==-1)){
		k=ask(x,y,x+2,y);
		if(k)a[x+2][y]=a[x][y];
		else a[x+2][y]=1-a[x][y];
		dfs2(x+2,y);
	}
	if(x<=n&&y+2<=n&&(a[x][y+2]==-1)){
		k=ask(x,y,x,y+2);
		if(k)a[x][y+2]=a[x][y];
		else a[x][y+2]=1-a[x][y];
		dfs2(x,y+2);
	}
	if(x+1<=n&&y+1<=n&&(a[x+1][y+1]==-1)){
		k=ask(x,y,x+1,y+1);
		if(k)a[x+1][y+1]=a[x][y];
		else a[x+1][y+1]=1-a[x][y];
		dfs2(x+1,y+1);
	}
	
	if(x-2>=1&&y>=1&&(a[x-2][y]==-1)){
		k=ask(x-2,y,x,y);
		if(k)a[x-2][y]=a[x][y];
		else a[x-2][y]=1-a[x][y];
		dfs2(x-2,y);
	}
	if(x>=1&&y-2>=1&&(a[x][y-2]==-1)){
		k=ask(x,y-2,x,y);
		if(k)a[x][y-2]=a[x][y];
		else a[x][y-2]=1-a[x][y];
		dfs2(x,y-2);
	}
	if(x-1>=1&&y-1>=1&&(a[x-1][y-1]==-1)){
		k=ask(x-1,y-1,x,y);
		if(k)a[x-1][y-1]=a[x][y];
		else a[x-1][y-1]=1-a[x][y];
		dfs2(x-1,y-1);
	}
}

void get(int x,int y,int xx,int yy){
	int i,j,k1,k2,k3,k4,k5,k6,k7,r1,r2,r3,r4;
	
	k1=ask(x,y,x+1,y+2);
	//k2=ask(x,y,x+2,y+1);
	//k3=ask(x+1,y,x+2,y+2);
	k4=ask(x,y+1,x+2,y+2);
	
	k5=ask(x,y+1,x+1,y+2);
	k6=ask(x+1,y,x+1,y+2);
	k7=ask(x+1,y,x+2,y+1);
	for(i=0;i<16;i++){
		r1=((i&b(1))>0);
		r2=((i&b(2))>0);
		r3=((i&b(3))>0);
		r4=((i&b(4))>0);
		
		if(((a[x][y]==r3&&r1==a[x+2][y])||(a[x][y]==r3&&r2==a[x+2][y]))!=k1){
			continue;
		}
		
		/*if(((a[x][y]==r4&&r1==a[x+2][y])||(a[x][y]==r4&&r2==a[x+2][y]))!=k2){
			continue;
		}*/
		
		if(((a[x+2][y+2]==r1&&r3==a[x+2][y])||(a[x+2][y+2]==r1&&r4==a[x+2][y]))!=k4){
			continue;
		}
		
		/*if(((a[x+2][y+2]==r2&&r3==a[x+2][y])||(a[x+2][y+2]==r2&&r4==a[x+2][y]))!=k3){
			continue;
		}*/
		
		if((r1==r3)!=k5)continue;
		if((r2==r3)!=k6)continue;
		if((r2==r4)!=k7)continue;
		a[x][y+1]=r1;
		a[x+1][y]=r2;
		a[x+1][y+2]=r3;
		a[x+2][y+1]=r4;
		return;
	}
}

int main(){
	scanf("%d",&n);
	memset(a,-1,sizeof(a));
	a[1][1]=1;
	a[n][n]=0;
	dfs(1,1);
	
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if((i+j)&1){
				if(a[i+1][j]^a[i][j+1]){
					if(i+1<=n&&j+2<=n){
						k=ask(i,j,i+1,j+2);
						if(k)a[i][j]=a[i+1][j+2];
						else a[i][j]=1-a[i+1][j+2];
					}
					else{
						k=ask(i,j,i+2,j+1);
						if(k)a[i][j]=a[i+2][j+1];
						else a[i][j]=1-a[i+2][j+1];
					}
					goto aaa;
				}
			}
		}
	}
	
	for(i=2;i<=n;i+=2){
		for(j=2;j<=n;j+=2){
			if(a[i-1][j-1]!=a[i+1][j+1]){
				get(i-1,j-1,i+1,j+1);
				goto aaa;
			}
		}
	}
	
	aaa:;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if((i+j)&1){
				dfs2(i,j);
			}
		}
	}
	
	puts("!");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d",a[i][j]);
		}
		puts("");
	}
}