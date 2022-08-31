#include <cstdio>
#include <cstring>

int t,n;
char s[5001];
bool check(int nx,int ny){
	if(!nx&&!ny)return 0;
	int x=0,y=0;
//	puts("");
	for(int i=1;i<=n;i++){
//		printf("%d %d\n",x,y);
		if(s[i]=='L'){
			if(!((x-1)==nx&&y==ny))--x; 
		}
		else if(s[i]=='R'){
			if(!((x+1)==nx&&y==ny))++x; 
		}
		else if(s[i]=='D'){
			if(!((y-1)==ny&&x==nx))--y;
		}
		else{
			if(!((y+1)==ny&&x==nx))++y;
//			printf("*%d %d\n",x,y);
		}
	}
	if(!x&&!y)return 1;
	return 0;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%s",s+1);
		n=strlen(s+1);
		int nx=0,ny=0;
		bool ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='L')--nx;
			else if(s[i]=='R')++nx;
			else if(s[i]=='D')--ny;
			else ++ny;
			if(check(nx,ny)){
				printf("%d %d\n",nx,ny);
				ans=1;
				break;
			}
		}
		if(!ans)puts("0 0");
	}
}