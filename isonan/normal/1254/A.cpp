#include <cstdio>

int T,r,c,k;
bool map[110][110];
int chk[110];
char ans[110][110];
bool vis[110][110];
bool get(){
	char ch=getchar();
	while(ch!='R'&&ch!='.')ch=getchar();
	return ch=='R';
}
int turn;
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d%d%d",&r,&c,&k);
		int cnt=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				cnt+=(map[i][j]=get());
		for(int i=0;i<k;i++)chk[i]=(cnt/k)+((cnt%k)>i);
		int x=1,y=1,now=0;
		cnt=0;
		for(int i=1;i<=r;i++)
			if(i&1)
				for(int j=1;j<=c;j++){
					ans[i][j]=(cnt<10?cnt+'0':(cnt<36?cnt-10+'a':cnt-36+'A'));
					now+=map[i][j];
					if(now==chk[cnt]&&cnt<k-1)++cnt,now=0;
				}
			else
				for(int j=c;j;j--){
					ans[i][j]=(cnt<10?cnt+'0':(cnt<36?cnt-10+'a':cnt-36+'A'));
					now+=map[i][j];
					if(now==chk[cnt]&&cnt<k-1)++cnt,now=0;
				}
		for(int i=1;i<=r;i++,putchar('\n'))
			for(int j=1;j<=c;j++)
				putchar(ans[i][j]);
	}
}