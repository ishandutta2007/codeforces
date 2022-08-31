#include <cstdio>

int t,n;
char str[100001];
int stk[100001],top;
void out(int k){
	for(int i=1;i<=k;++i)putchar(str[i]);
	for(int i=k;i;--i)putchar(str[i]);putchar('\n');
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		scanf("%s",str+1);
		for(int i=1;i<n;++i)
			if(str[i]<str[i+1]){
				n=i;
				break;
			}
		if(n>1&&str[1]==str[2])out(1);
		else out(n);
	}
}