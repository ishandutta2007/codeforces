#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
int n;
int a[55][55],b[55][55];
void go(int x,int y){
	if(x+2<=n&&a[x+2][y]==-1){
		printf("? %d %d %d %d\n",x,y,x+2,y);fflush(stdout);
		int ans;
		scanf("%d",&ans);
		if(ans==1)a[x+2][y]=a[x][y];
		else a[x+2][y]=!a[x][y];
		go(x+2,y);
	}
	if(y+2<=n&&a[x][y+2]==-1){
		printf("? %d %d %d %d\n",x,y,x,y+2);fflush(stdout);
		int ans;
		scanf("%d",&ans);
		if(ans==1)a[x][y+2]=a[x][y];
		else a[x][y+2]=!a[x][y];
		go(x,y+2);
	}
	if(x+1<=n&&y+1<=n&&a[x+1][y+1]==-1){
		printf("? %d %d %d %d\n",x,y,x+1,y+1);fflush(stdout);
		int ans;
		scanf("%d",&ans);
		if(ans==1)a[x+1][y+1]=a[x][y];
		else a[x+1][y+1]=!a[x][y];
		go(x+1,y+1);
	}
}
void go2(int x,int y);
void get(int x,int y,int x1,int y1);
int w[10],w2[10],ww,ww2;
int ask[4][4]={{1,1,2,3},{1,1,3,2},{1,2,3,3},{2,1,3,3}};
void pd(int x,int y,int x1,int y1){
	++ww;
	if(a[x][y]==a[x1][y1]){
		if(a[x+1][y]==a[x1][y1-1]||a[x][y+1]==a[x1-1][y1])
			w[ww]=1;
	}
}
void pd2(int x,int y,int x1,int y1){
	++ww2;
	if(a[x][y]==a[x1][y1]){
		if(a[x+1][y]==a[x1][y1-1]||a[x][y+1]==a[x1-1][y1])
			w2[ww2]=1;
	}
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)fo(j,1,n)a[i][j]=-1,b[i][j]=-1;
	a[1][1]=1;
	a[n][n]=0;
	go(1,1);
	
	b[2][3]=0;
	printf("? 2 1 2 3\n");fflush(stdout);
	int ans;scanf("%d",&ans);
	if(ans==1)b[2][1]=b[2][3];else b[2][1]=!b[2][3];
	printf("? 1 2 2 3\n");fflush(stdout);
	scanf("%d",&ans);
	if(ans==1)b[1][2]=b[2][3];else b[1][2]=!b[2][3];
	go2(1,2);go2(2,3);go2(2,1);
	int xx;
	fo(i,1,n-2)
		if(a[i][i]!=a[i+2][i+2]){
			xx=i;
			break;
		}
	fo(j,0,3)fo(k,0,3)
		ask[j][k]+=xx-1;
	
	fo(i,1,n)fo(j,1,n)if(b[i][j]!=-1)a[i][j]=b[i][j];
	fo(j,0,3)pd(ask[j][0],ask[j][1],ask[j][2],ask[j][3]);
	fo(i,1,n)fo(j,1,n)if(b[i][j]!=-1)a[i][j]=!b[i][j];
	fo(j,0,3)pd2(ask[j][0],ask[j][1],ask[j][2],ask[j][3]);
	
	fo(j,0,3)if(w[j+1]!=w2[j+1]){
		printf("? ");
		fo(k,0,3)printf("%d ",ask[j][k]);
		printf("\n");fflush(stdout);
		scanf("%d",&ans);
		if(ans==w[j+1]){
			fo(i,1,n)fo(j,1,n)if(b[i][j]!=-1)a[i][j]=b[i][j];
		}
		break;
	}
	
	printf("!\n");fflush(stdout);
	fo(i,1,n){
		fo(j,1,n)putchar(a[i][j]+'0');
		printf("\n");fflush(stdout);
	}
	
}
void go2(int x,int y){
	if(x+2<=n&&b[x+2][y]==-1){
		get(x,y,x+2,y);
		go2(x+2,y);
	}
	if(y+2<=n&&b[x][y+2]==-1){
		get(x,y,x,y+2);
		go2(x,y+2);
	}
	if(x+1<=n&&y+1<=n&&b[x+1][y+1]==-1){
		get(x,y,x+1,y+1);
		go2(x+1,y+1);
	}
}
void get(int x,int y,int x1,int y1){
	printf("? %d %d %d %d\n",x,y,x1,y1);fflush(stdout);
	int ans;scanf("%d",&ans);
	if(ans==1)b[x1][y1]=b[x][y];else b[x1][y1]=!b[x][y];
}