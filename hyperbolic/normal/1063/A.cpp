#include <stdio.h>
#include <String.h>

char x[100010];
int S[30];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	
	for(int i=1;i<=a;i++) S[x[i]-'a']++;
	for(int i=0;i<=26;i++)
	{
		while(S[i]--) printf("%c",i+'a');
	}
}