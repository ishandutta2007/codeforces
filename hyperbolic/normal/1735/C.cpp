#include <stdio.h>
#include <vector>

int next[110],check[110];
char x[200010];

int next2[110];
int find(int k)
{
	if(k==next2[k]) return k;
	else return next2[k] = find(next2[k]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		for(int i=0;i<26;i++) next2[i] = i;
		for(int i=0;i<26;i++) next[i] = -1;
		for(int i=0;i<26;i++) check[i] = 0;
		
		for(int i=1;i<=a;i++)
		{
			if(next[x[i]-'a']==-1)
			{
				int p;
				for(int j=0;j<26;j++)
				{
					if(check[j]==1) continue;
					int s = find(x[i]-'a');
					int t = find(j);
					if(s!=t)
					{
						next[x[i]-'a'] = j;
						check[j] = 1;
						next2[s] = t;
						goto u;
					}
				}
				p = -1;
				for(int j=0;j<26;j++) if(check[j]==0) p = j;
				next[x[i]-'a'] = p;
				u:;
			}
		}
		
		for(int i=1;i<=a;i++) printf("%c",'a'+next[x[i]-'a']);
		printf("\n");
	}
}