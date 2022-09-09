#include<cstdio>

using namespace std;

int DIG(int r,int c)
{
	printf("DIG %d %d\n",r,c);fflush(stdout);int x=0;scanf("%d",&x);return x;
}
int SCAN(int r,int c)
{
	printf("SCAN %d %d\n",r,c);fflush(stdout);int x=0;scanf("%d",&x);return x;
}

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0,m=0;scanf("%d%d",&n,&m);
		int tot1=SCAN(1,1),tot2=SCAN(1,m);
		int sx=(tot1+tot2+6-2*m)/2,sy=tot1-sx+4;
		int tot3=SCAN(1,sy/2),tot4=SCAN(sx/2,1);
		int dy=tot3+2-sx,dx=tot4+2-sy;
		int lx=(sx-dx)/2,rx=(sx+dx)/2,ly=(sy-dy)/2,ry=(sy+dy)/2;
		if(DIG(lx,ly)){DIG(rx,ry);}
		else{DIG(lx,ry);DIG(rx,ly);}
	}
}