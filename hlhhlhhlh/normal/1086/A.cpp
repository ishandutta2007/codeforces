// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
struct node{
	int x,y;
}a[maxn],ans[maxn];
int n,x,y;
int mi,thi;
int ha[2010][2010];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	a[1].x=read(); a[1].y=read();
	a[2].x=read(); a[2].y=read();
	a[3].x=read(); a[3].y=read();
	for (i=1;i<=2;i++){
		if ((a[i].x>a[3].x)||(a[i].x==a[3].x)&&(a[i].y>a[3].y)) swap(a[i],a[3]);
	}
	if ((a[1].x>a[2].x)||(a[1].x==a[2].x)&&(a[1].y>a[2].y)) swap(a[1],a[2]);
	for (i=a[1].x;i<=a[2].x;i++){
		n++;
		ans[n].y=a[1].y;
		ans[n].x=i;
		ha[ans[n].x][ans[n].y]=1;
	}
	x=ans[n].x; y=ans[n].y;
	while ((x!=a[2].x)||(y!=a[2].y)){
		if (abs(y+1-a[2].y)<abs(y-1-a[2].y)){
			y=y+1;
			n++; ans[n].x=x; ans[n].y=y;
			ha[ans[n].x][ans[n].y]=1;
		}
		else{
			y=y-1;
			n++; ans[n].x=x; ans[n].y=y;	
			ha[ans[n].x][ans[n].y]=1;
		}
	}
	mi=1e9; thi=0;
	for (i=1;i<=n;i++){
		if (abs(ans[i].x-a[3].x)+abs(ans[i].y-a[3].y)<mi){
			mi=abs(ans[i].x-a[3].x)+abs(ans[i].y-a[3].y);
			thi=i;
		}
	}
	x=ans[thi].x; y=ans[thi].y;
	while ((x!=a[3].x)||(y!=a[3].y)){
		if (abs(y+1-a[3].y)<abs(y-a[3].y)){
			y=y+1;
			n++; ans[n].x=x; ans[n].y=y;
			ha[ans[n].x][ans[n].y]=1;
		}
		if (abs(y-1-a[3].y)<abs(y-a[3].y)){
			y=y-1;
			n++; ans[n].x=x; ans[n].y=y;	
			ha[ans[n].x][ans[n].y]=1;
		}
		if (abs(x+1-a[3].x)<abs(x-a[3].x)){
			x=x+1;
			n++; ans[n].x=x; ans[n].y=y;
			ha[ans[n].x][ans[n].y]=1;
		}
		if (abs(x-1-a[3].x)<abs(x-a[3].x)){
			x=x-1;
			n++; ans[n].x=x; ans[n].y=y;	
			ha[ans[n].x][ans[n].y]=1;
		}
	}
	printf("%d\n",n);
	for (i=1;i<=n;i++){
		printf("%d %d\n",ans[i].x,ans[i].y);
	}
	return 0;
}