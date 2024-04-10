#include<cstdio>

char a[200][200];
int d[30][30];
char s[30];

int main()
{
	char t;
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%s",a[i]);
	for(i=1;i<n;i++)
	{
		for(j=0;a[i][j]&&a[i][j]==a[i-1][j];j++);
        if(a[i][j]&&a[i-1][j])d[a[i][j]-'a'][a[i-1][j]-'a']=1;
        if(!a[i][j]&&a[i-1][j])
		{
			puts("Impossible");
			return 0;
		}
	}
	for(i=0;i<26;i++)s[i]=i+'a';
	for(i=0;i<1000;i++)for(j=0;j<26;j++)for(k=j+1;k<26;k++)if(d[s[j]-'a'][s[k]-'a'])
	{
        t=s[j];
        s[j]=s[k];
        s[k]=t;
	}
	for(j=0;j<26;j++)for(k=j+1;k<26;k++)if(d[s[j]-'a'][s[k]-'a'])
	{
		puts("Impossible");
		return 0;
	}
	puts(s);
	return 0;
}