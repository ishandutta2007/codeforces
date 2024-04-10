#include<bits/stdc++.h>
const int MAXN=50+5;
const int dx[]={1,1,1,2},dy[]={-1,0,1,0};
int n;
char a[MAXN+5][MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",a[i]+1);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]=='.'){
				a[i][j]='#';
				for(int k=0;k<4;++k){
					int x=i+dx[k],y=j+dy[k];
					if(x>=1&&x<=n&&y>=1&y<=n&&a[x][y]=='.'){
						a[x][y]='#';
					}else{
						puts("NO");
						return 0;
					}
				}
			}
		}
	}
	puts("YES");
	return 0;
}