#include<bits/stdc++.h>
using namespace std;
const int M=509;
int n,m;
int d[250009];
char s[M][M];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int f(int i,int j){return (i-1)*m+j;}
bool pd(int x,int y){
	return s[x][y-1]!='X'&&s[x][y+1]!='X'&&s[x+1][y-1]!='X'&&s[x+1][y+1]!='X';
}
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		if(i%3==1){
			for(int j=1;j<=m;++j){
				s[i][j]='X';
			}
		}
	}
	for(int i=2;i<n;i+=3){
		for(int j=1;j<=m;++j){
			if(pd(i,j)){
				s[i][j]='X';
				s[i+1][j]='X';
				if(i!=n-1)break; 
			}
		}
	}
	for(int i=1;i<=n;++i){
		printf("%s\n",s[i]+1);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}