#include <cstdio>
#define qx q[h][0]
#define qy q[h][1]
#define qsl q[h][2]
#define qsr q[h][3]

bool map[2001][2001],vis[2001][2001];
int n,m,r,c,x,y,q[4000001][4],h,t,tot,minn[2001][2001][2];
char opt;
int max(int a,int b){
	return a>b?a:b;
}
void push(int x,int y,int sl,int sr){
	if(!x||!y||x>n||y>m||(map[x][y]&&minn[x][y][0]>=sl&&minn[x][y][1]>=sr)||vis[x][y])return;
	t++;
	if(!map[x][y])tot++;
	minn[x][y][0]=max(minn[x][y][0],sl);
	minn[x][y][1]=max(minn[x][y][1],sr);
	map[x][y]=1;
	q[t][0]=x;
	q[t][1]=y;
	q[t][2]=sl;
	q[t][3]=sr;
}
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			opt=getchar();
			while(opt!='.'&&opt!='*')opt=getchar();
			vis[i][j]=(opt=='*');
		}
	push(r,c,x,y);
	while(h<t){
		h++;
		push(qx-1,qy,qsl,qsr);
		push(qx+1,qy,qsl,qsr);
		if(qsl)push(qx,qy-1,qsl-1,qsr);
		if(qsr)push(qx,qy+1,qsl,qsr-1);
	}
	printf("%d\n",tot);
}