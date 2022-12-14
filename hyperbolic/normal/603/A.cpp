#include <stdio.h>
char x[100010];
int s1[100010],a;
int s2[100010];
int func2(int k);
int func1(int k)
{
	if(k>a) return 0;
	if(s1[k]!=-1) return s1[k];
	//    1 
	if(x[k]=='1') s1[k] = func1(k+1);
	else s1[k] = func2(k+1)+1;
	return s1[k];
}
int func2(int k)
{
	if(k>a) return 0;
	if(s2[k]!=-1) return s2[k];
	//   0 
	if(x[k]=='1') s2[k] = func1(k+1)+1;
	else s2[k] = func2(k+1);
	return s2[k];
}
int main()
{
	int i,count=0,ans;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(i=1;i<=a;i++)
	{
		s1[i]=-1;
		s2[i]=-1;
	}
	for(i=1;i<a;i++)
	{
		if(x[i]==x[i+1])
		{
			count++;
		}
	}
	ans = func1(1) > func2(1) ? func1(1) : func2(1);
	if(count>2) count = 2;
	printf("%d",ans+count);
}