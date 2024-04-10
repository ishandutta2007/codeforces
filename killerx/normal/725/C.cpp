#include<cstdio>
int n=27,m=13;
int x,y;
char c[30];
char ans[2][15];
int main(){
	scanf("%s",c);
	for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)if(c[i]==c[j])x=i,y=j;
	if(y==x+1){puts("Impossible");return 0;}
	int l=y-x>>1;
	for(int i=0;i<m;++i)ans[0][i]=ans[1][i]=' ';
	for(int i=0;i<y-x-1-l;++i)ans[0][m-y+x+1+l+i]=c[x+i+1];
	for(int i=0;i<l;++i)ans[1][m-l+i]=c[y-i-1];
	ans[0][m-y+x+1+l-1]=c[x];
	for(int nx=0,ny=m-y+x+1+l-2,i=x-1;~i;--i){
		if(ny<0)++nx,ny=0;
		ans[nx][ny]=c[i];
		if(nx){if(ny<m-1)++ny;else--nx;}
		else{if(ny)--ny;else++nx;}
	}
	for(int nx=1,ny=m-l-1,i=y+1;i<n;++i){
		if(ny<0)--nx,ny=0;
		ans[nx][ny]=c[i];
		if(nx){if(ny)--ny;else--nx;}
		else{if(ny<m-1)++ny;else++nx;}
	}
	puts(ans[0]);puts(ans[1]);
	return 0;
}