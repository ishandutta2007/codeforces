#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define mo 1000000007
using namespace std;
int n;
int bd[3][10005];
int xx,yy;
inline int down(){return xx==0 && bd[1][yy]==0 && bd[2][yy]==0;}
inline int lef(){return yy>=3 && bd[xx][yy-1]==0 && bd[xx][yy-2]==0;}
inline int rig(){return yy<=n-2 && bd[xx][yy+1]==0 && bd[xx][yy+2]==0;} 
inline int sdown(int i){bd[1][yy]=bd[2][yy]=i;}
inline int slef(int i){bd[xx][yy-1]=bd[xx][yy-2]=i;}
inline int srig(int i){bd[xx][yy+1]=bd[xx][yy+2]=i;}
int ans=0;
int f[10005][8];
void upd(int &x,int b){
	x+=b;if(x>=mo)x-=mo;
}
void work(int sg){
	bd[0][0]=bd[1][0]=bd[2][0]=1;
	memset(f,0,sizeof(f));
	int ini=(1<<3)-1;
	f[0][ini]=1;
	for (int i=0;i<n;i++){
		int d=bd[0][i+1]|bd[1][i+1]<<1|bd[2][i+1]<<2;
		for (int j=0;j<1<<3;j++)if(f[i][j]){
			int ne=d|j;
			if(ne!=j)continue;
			int noo=d|(7-j);
			upd(f[i+1][noo],f[i][j]);
			if(!(noo&3))upd(f[i+1][noo|3],f[i][j]);
			if(!(noo&6))upd(f[i+1][noo|6],f[i][j]);
		}
	}
	int mx=f[n][7];
	mx*=sg;
	if(mx<0)mx+=mo;
	upd(ans,mx);
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<3;i++)
		for (int j=1;j<=n;j++){
			char c;while((c=getchar())!='.' && c!='X' && c!='O');
			if(c=='.')bd[i][j]=0;
			else if(c=='X')bd[i][j]=1;
			else bd[i][j]=1,xx=i,yy=j;
		}
	if(xx==2){
		xx=0;
		for (int j=1;j<=n;j++)swap(bd[0][j],bd[2][j]);
	}
	if(down())sdown(1),work(1),sdown(0);
	if(lef())slef(1),work(1),slef(0);
	if(rig())srig(1),work(1),srig(0);
	if(down() && lef())sdown(1),slef(1),work(-1),sdown(0),slef(0);
	if(down() && rig())sdown(1),srig(1),work(-1),sdown(0),srig(0);
	if(lef() && rig())slef(1),srig(1),work(-1),slef(0),srig(0);
	if(down() && lef() && rig())sdown(1),slef(1),srig(1),work(1),sdown(0),slef(0),srig(0);
	printf("%d\n",ans);
	return 0;
}