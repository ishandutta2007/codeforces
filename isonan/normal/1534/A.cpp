#include <cstdio>

int t;
int n,m;
char str[1001][1001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%s",str[i]+1);
		int stat=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)
				if(str[i][j]!='.'){
					stat|=(1<<((str[i][j]=='R')^(i&1)^(j&1)));
				}
		}
		if(!stat)stat=2;
		if(stat==3){
			puts("NO");
			continue;
		}
		puts("YES");
		if(stat==2){
			for(int i=1;i<=n;++i,putchar('\n'))
				for(int j=1;j<=m;++j)
					if(1^(i&1)^(j&1))putchar('R');
					else putchar('W');
		}
		else{
			for(int i=1;i<=n;++i,putchar('\n'))
				for(int j=1;j<=m;++j)
					if((i&1)^(j&1))putchar('R');
					else putchar('W');
		}
	}
}