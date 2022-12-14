#include <stdio.h>
#include <vector>

void func(int k)
{
	if(k==0) printf("a");
	else if(k<=26) printf("%c",'a'+k-1);
	else if(k<=52) printf("%c",'A'+k-27);
	else printf("%c",'0'+k-53);
}

int check[110][110];
char x[110][110];
std::vector<int> save;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		int count = 0;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='R') count++;
		
		save.clear();
		for(int i=1;i<=c-(count%c);i++) save.push_back(count/c);
		for(int i=1;i<=(count%c);i++) save.push_back(count/c + 1);
		
		int s = 1, t = 1;
		int p = 1;
		for(int i=0;i<save.size();i++)
		{
			int C = save[i];
			while(C)
			{
				check[s][t] = p;
				if(x[s][t]=='R') C--;
				if(s%2==1)
				{
					if(t==b) s++;
					else t++;
				}
				else
				{
					if(t==1) s++;
					else t--;
				}
			}
			p++;
		}
		
		p--;
		while(1)
		{
			if(s>a) break;
			check[s][t] = p;
			if(s%2==1)
			{
				if(t==b) s++;
				else t++;
			}
			else
			{
				if(t==1) s++;
				else t--;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++) func(check[i][j]);
			printf("\n");
		}
	}
}