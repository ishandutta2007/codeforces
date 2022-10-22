// user:halahen
#include<bits/stdc++.h>
using namespace std;
int i,j,k;
char c=' ';
int a,b,x,y;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	while (((c<'0')||(c>'9'))&&((c<'A')||(c>'Z'))) { c=getchar(); }
	a=c; c=getchar(); b=c; c=getchar();
	for (i=1;i<=5;i++){
		while (((c<'0')||(c>'9'))&&((c<'A')||(c>'Z'))) { c=getchar(); }
		x=c;
		c=getchar();
		y=c;
		c=getchar();
		if ((a==x)||(b==y)){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}