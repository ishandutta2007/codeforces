#include <cstdio>

int x,n,y;
char str[200001];
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++){
		if(str[i]=='(')++x;
		else{
			if(!x)++y;
			else --x;
		}
	}
	if((x==1&&y==1)||(x==0&&y==0))puts("Yes");
	else puts("No");
}