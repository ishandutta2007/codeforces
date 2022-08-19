#include <cstdio>

char str[1001];
int n,tot;
char get(){
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	return ch;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		str[i]=get();
		if(str[i]=='8')tot++;
	}
	if(tot>n/11)tot=n/11;
	printf("%d\n",tot);
}