#include<cstdio>

char a[20];

int main()
{
  int i;
  scanf("%s",&a);
  if(a[0]>'4'&&a[0]<'9')a[0]=9-(a[0]-'0')+'0';
  for(i=1;a[i];i++)if(a[i]>'4')a[i]=9-(a[i]-'0')+'0';
  printf("%s",a);
}