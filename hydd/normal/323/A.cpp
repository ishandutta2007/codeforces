#include<bits/stdc++.h>
using namespace std;
const char ch[2]={'b','w'};
int k,num[110][110];
int main(){
	scanf("%d",&k);
	if (!(k&1)){
		memset(num,-1,sizeof(num));
		int now=0;
		for (int i=1;i<=k;i++){
			now^=1;
			for (int x=1;x<=k;x++)
				if (num[x][i]==-1) num[x][i]=now;
			for (int x=1;x<=k;x++)
				if (num[x][k-i+1]==-1) num[x][k-i+1]=now;
			for (int y=1;y<=k;y++)
				if (num[i][y]==-1) num[i][y]=now;
			for (int y=1;y<=k;y++)
				if (num[k-i+1][y]==-1) num[k-i+1][y]=now;
		}
		
		now=0;
		for (int i=1;i<=k;i++){
			now^=1;
			for (int x=1;x<=k;x++){
				for (int y=1;y<=k;y++) putchar(ch[num[x][y]^now]);
				putchar('\n');
			}
			putchar('\n');
		}
	} else puts("-1");
	return 0;
}