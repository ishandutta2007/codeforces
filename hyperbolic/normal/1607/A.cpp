#include <stdio.h>
#include <string.h>
char x[110],y[110];
int abs(int k)
{
	return k>0?k:-k;
}

int dist[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		for(int i=1;i<=26;i++) dist[x[i]-'a'] = i;
		scanf("%s",y+1);
		int a = strlen(y+1);
		
		int ans = 0;
		for(int i=1;i<a;i++) ans += abs(dist[y[i]-'a']-dist[y[i+1]-'a']);
		printf("%d\n",ans);
	}
}