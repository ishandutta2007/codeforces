#include <cstdio>

char get(){
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	return ch;
}
int n,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cnt+=get()=='z';
	}
	for(int i=1;i<=(n-cnt*4)/3;i++)printf("1 ");
	for(int i=1;i<=cnt;i++)printf("0 ");
}