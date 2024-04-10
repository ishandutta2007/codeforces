#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int n,m,N=1,M,i,j,k,a[5005][1005],s1,s2,c[50005][26],x[50005],y[2];
char s[5005][15],t[1005],t1[15],t2[1005],m1[1005],m2[1005];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)a[n][i]=2;
	for(i=0;i<n;i++)
	{
		scanf("%s%*s%s",s[i],t);
		M=strlen(s[i]);
		for(j=0,k=1;j<M;k=c[k][s[i][j++]-'a'])if(!c[k][s[i][j]-'a'])c[k][s[i][j]-'a']=++N;
		x[k]=i;
		if(t[0]=='0'||t[0]=='1')for(j=0;j<m;j++)a[i][j]=t[j]^'0';
		else
		{
			scanf("%s%s",t1,t2);
			if(t[0]=='?')s1=n;
			else
			{
				M=strlen(t);
				for(j=0,k=1;j<M;k=c[k][t[j++]-'a']);
				s1=x[k];
			}
			if(t2[0]=='?')s2=n;
			else
			{
				M=strlen(t2);
				for(j=0,k=1;j<M;k=c[k][t2[j++]-'a']);
				s2=x[k];
			}
			for(j=0;j<m;j++)if(t1[0]=='A')if(!a[s1][j]||!a[s2][j])a[i][j]=0;
			else if(a[s1][j]==1)a[i][j]=a[s2][j];
			else if(a[s2][j]==1)a[i][j]=a[s1][j];
			else if(a[s1][j]==a[s2][j])a[i][j]=a[s1][j];
			else a[i][j]=0;
			else if(t1[0]=='O')if(a[s1][j]==1||a[s2][j]==1)a[i][j]=1;
			else if(!a[s1][j])a[i][j]=a[s2][j];
			else if(!a[s2][j])a[i][j]=a[s1][j];
			else if(a[s1][j]==a[s2][j])a[i][j]=a[s1][j];
			else a[i][j]=1;
			else if(a[s1][j]<2||a[s2][j]<2)a[i][j]=a[s2][j]^a[s1][j];
			else a[i][j]=a[s1][j]!=a[s2][j];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=y[0]=y[1]=0;j<n;j++)if(a[j][i]>1)y[a[j][i]-2]++;
		if(y[0]==y[1])m1[i]=m2[i]='0';
		else if(y[0]>y[1])
		{
			m1[i]='0';
			m2[i]='1';
		}
		else
		{
			m1[i]='1';
			m2[i]='0';
		}
	}
	puts(m1);
	puts(m2);
	return 0;
}