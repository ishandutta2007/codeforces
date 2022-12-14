#include <stdio.h>
#include <set>

std::set< std::pair<char,char> > S;
char x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		int count = 0;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]>y[i])
			{
				printf("-1\n");
				goto u;
			}
		}
		
		for(int i=0;i<20;i++)
		{
			int c = 21;
			for(int j=1;j<=a;j++) if(x[j]=='a'+i && x[j]<y[j]) c = c<y[j]-'a'?c:y[j]-'a';
			if(c<21)
			{
				count++;
				for(int j=1;j<=a;j++)
				{
					if(x[j]=='a'+i&&x[j]<y[j]) x[j] = 'a'+c;
				}
			}
		}
		printf("%d\n",count);
		u:;
	}
}