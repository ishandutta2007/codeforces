#include <stdio.h>

char x[100010];
int count[30],check[30];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<26;i++) count[i] = 0;
		
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) count[x[i]-'a']++;
		
		for(int i=0;i<26;i++) if(count[i]%b!=0) goto u1;
		
		for(int i=1;i<=a;i++) printf("%c",x[i]);
		printf("\n");
		continue;
		u1:;
		
		for(int i=a;i>=1;i--)
		{
			count[x[i]-'a']--;
			for(char j=x[i]+1;j<='z';j++)
			{
				count[j-'a']++;
				for(int k=0;k<26;k++) check[k] = (b-(count[k]%b))%b;
				int sum = 0;
				for(int k=0;k<26;k++) sum += check[k];
				if(sum <= (a-i) && (a-i-sum)%b==0)
				{
					check[0] += ((a-i)-sum);
					for(int k=1;k<i;k++) printf("%c",x[k]);
					printf("%c",j);
					for(int k=0;k<26;k++) for(int l=1;l<=check[k];l++) printf("%c",'a'+k);
					printf("\n");
					goto u2;
				}
				count[j-'a']--;
			}
		}
		printf("-1\n");
		u2:;
	}
}