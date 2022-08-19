#include <cstdio>
#include <cstring>

int T;
int edg[1000001][2];
char str[500001];
void walk(int x){
	if(edg[x][1]&&(!edg[x][0]||edg[x-1][0])){
		putchar('0');
		--edg[x][1];
		walk(x-1);
	}
	else if(edg[x][0]){
		putchar('1');
		--edg[x][0];
		walk(x+1);
	}
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%s",str+1);
		int nl=strlen(str+1);
		for(int sum=0,i=1;i<=nl;i++){
			++edg[sum+500000][str[i]=='0'];
			sum+=(str[i]=='0'?-1:1);
		}
		walk(500000);
		putchar('\n');
	}
}