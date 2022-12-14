#include <stdio.h>

int next[600010],size[600010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

char x[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=0;i<=2*a+1;i++) next[i] = i;
		for(int i=0;i<=2*a+1;i++) size[i] = 1;
		for(int i=1;i<=a;i++)
		{
			int s,t;
			if(x[i]=='L') s = i, t = (i-1)+(a+1);
			else s = i-1, t = i+(a+1);
			s = find(s);
			t = find(t);
			if(s!=t)
			{
				next[s] = t;
				size[t] += size[s];
			}
		}
		
		for(int i=0;i<=a;i++) printf("%d ",size[find(i)]);
		printf("\n");
	}
}