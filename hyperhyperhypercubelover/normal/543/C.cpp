#include<cstdio>
#include<algorithm>

char s[22][22];
int a[22][22];
int d[2222222];

int tt[33],ttt[33],tttt[33];

int main()
{
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&a[i][j]);
    for(i=1;i<2222222;i++)d[i]=1e9;
    for(j=0;j<m;j++)
	{
		for(i=0;i<26;i++)
		{
			tt[i]=0;
			ttt[i]=0;
			tttt[i]=0;
		}
        for(i=0;i<n;i++)
		{
			tt[s[i][j]-'a']+=a[i][j];
			ttt[s[i][j]-'a']=std::max(ttt[s[i][j]-'a'],a[i][j]);
			tttt[s[i][j]-'a']|=(1<<i);
		}
		for(i=0;i<26;i++)tt[i]-=ttt[i];
        for(i=0;i<(1<<n);i++)for(k=0;k<n;k++)
		{
			if(d[i|tttt[s[k][j]-'a']]>d[i]+tt[s[k][j]-'a'])d[i|tttt[s[k][j]-'a']]=d[i]+tt[s[k][j]-'a'];
			if(d[i|(1<<k)]>d[i]+a[k][j])d[i|(1<<k)]=d[i]+a[k][j];
		}
	}
	printf("%d",d[(1<<n)-1]);
}