#include <stdio.h>

int count[110];
char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) count[x[i]-'a']++;
	int s1 = count['n'-'a'];
	s1 = s1 < count['o'-'a']? s1 : count['o'-'a'];
	s1 = s1 < count['e'-'a']? s1 : count['e'-'a'];
	
	for(int i=1;i<=s1;i++) printf("1 ");
	count['o'-'a'] -= s1;
	count['e'-'a'] -= s1;
	
	int s2 = count['z'-'a'];
	s2 = s2 < count['e'-'a']?s2 : count['e'-'a'];
	s2 = s2 < count['r'-'a']?s2 : count['r'-'a'];
	s2 = s2 < count['o'-'a']?s2 : count['o'-'a'];
	for(int i=1;i<=s2;i++) printf("0 ");
}