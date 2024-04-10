#include<bits/stdc++.h>
const int MAXN=1000;
int n,m;
int a[MAXN][MAXN];
bool t;
char read_char(){
	char c=getchar();
	while(isspace(c))
		c=getchar();
	return c;
}
void kill(){
	puts("NO");
	exit(0);
}
bool check1(int x,int y,int t){
	return x<0||y<0||x==n||y==m||a[x][y]!=t;
}
bool check(int x,int y,int t){
	return check1(x,y-1,t)&&check1(x,y+1,t)&&check1(x-1,y,t)&&check1(x+1,y,t);
}
void put(int x,int y,int t){
	if(t){
		if(x+2>=n||a[x+1][y]||a[x+2][y])
			kill();
		else
			for(int i=1;i<=4;++i)
				if(check(x,y,i)&&check(x+1,y,i)&&check(x+2,y,i))
					return void(a[x][y]=a[x+1][y]=a[x+2][y]=i);
	}else if(y+2>=m||a[x][y+1]||a[x][y+2])
		kill();
	else
		for(int i=1;i<=4;++i)
			if(check(x,y,i)&&check(x,y+1,i)&&check(x,y+2,i))
				return void(a[x][y]=a[x][y+1]=a[x][y+2]=i);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			char c=read_char();
			if(c!='.')
				t=(i+j)&1^(c=='w');
			a[i][j]=-(c=='.');
		}
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(a[i][j])
				continue;
			else if(!(((i+j)&1)^t))
				kill();
			else if(j+1==m||a[i][j+1])
				put(i,j,1);
			else
				put(i,j,0);
	puts("YES");
	for(int i=0;i<n;++i,puts(""))
		for(int j=0;j<m;++j)
			putchar(a[i][j]==-1?'.':a[i][j]+'a'-1);
	return 0;
}