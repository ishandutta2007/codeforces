// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	if (n%3==0){
		printf("1 1 %d\n",n-2);
	}
	if (n%3==1){
		printf("2 1 %d\n",n-3);
	}
	if (n%3==2){
		printf("2 2 %d\n",n-4);
	}
	return 0;
}