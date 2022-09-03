#include<cstdio>
#include<algorithm>

char s[1111111];
int f[1111111];
int c[1111111];
int d[1111111];

int main()
{
	int i,j,n,m,l;
	scanf("%d%d%s",&n,&m,s);
	if(m==0)
	{
        j=1;
        for(i=0;i<n;i++)j=26LL*j%1000000007;
        printf("%d",j);
        return 0;
	}
    f[0]=-1;
    for(i=1;s[i];i++)
	{
        for(j=f[i-1];;j=f[j])
		{
			if(s[j+1]==s[i])break;
            if(j==-1)break;
		}
        if(s[j+1]==s[i])f[i]=j+1;
        else f[i]=-1;
	}
	l=i;
    for(j=f[l-1];j>=0;j=f[j])c[l-j-1]=1;
    scanf("%d",&i);
    d[i-1]=l;
    while(--m)
	{
		scanf("%d",&j);
        if(j-i<l&&!c[j-i])
		{
			puts("0");
			return 0;
		}
        d[j-1]=l;
        i=j;
	}
	j=1;
	for(i=0;i<n;i++)
	{
		if(i)d[i]=std::max(d[i-1]-1,d[i]);
        if(d[i]==0)j=26LL*j%1000000007;
	}
	printf("%d",j);
}