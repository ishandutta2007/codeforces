#include <cstdio>
#include <algorithm>

int p[1001],n;
bool vis[1001];
int map[1001][1001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	bool cando=1;
	for(int i=1;i<=n;i++)cando&=p[i]==i;
	if(cando){
		printf("%d\n",n);
		for(int i=1;i<=n;i++,putchar('\n'))
			for(int j=1;j<=n;j++)
				putchar('.');
		return 0;
	}
	int last,pos;
	for(int i=1;i<=n;i++)if(p[i]!=i)last=i;
	char x='/',y='\\';
	for(int i=n;i;i--){
		pos=0;
		if(x=='/')for(int j=1;j<last;j++){if(p[j]!=j){pos=j;break;}}
		else	  for(int j=n;j>last;j--){if(p[j]!=j){pos=j;break;}}
		if(!pos)break;
		map[i][pos]=map[i][p[pos]]=map[i][last]=x;
		p[last]=p[p[pos]],p[p[pos]]=p[pos],last=pos;
		x^=y^=x^=y;
	}
	printf("%d\n",n-1);
	for(int i=1;i<=n;i++,putchar('\n'))
		for(int j=1;j<=n;j++)
			putchar(map[i][j]?map[i][j]:'.');
}