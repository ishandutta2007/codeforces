#include<cstdio>
#include<cstring>
#include<algorithm>

char a[111111];

int main()
{
	int i,n;
	scanf("%s",a);
	n=strlen(a);
	for(i=0;i<n;i++)if((a[i]-'0')%2==0&&a[i]<a[n-1])break;
    if(i<n)
	{
		std::swap(a[i],a[n-1]);
        puts(a);
        return 0;
	}
	for(i=n-1;i>=0;i--)if((a[i]-'0')%2==0)break;
	if(i>=0)
	{
		std::swap(a[i],a[n-1]);
		puts(a);
		return 0;
	}
	puts("-1");
}