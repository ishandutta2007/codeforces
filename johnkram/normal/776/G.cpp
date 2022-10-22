#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n1,n2,m,n,i,j,k,l,a1[100],a2[100];
char s1[100],s2[100];
ll ans;
ll f[20][2][2],g[20][20][20][2];
ll work(int n,int *a)
{
	ll s=0;
	for(i=1;i<n;i++)for(j=0;j<16;j++)s+=g[i][j][0][1];
	for(m=0;m<16&&m<(n<<2);m++)
	{
		memset(f,0,sizeof(f));
		f[n][0][1]=1;
		for(i=n;i;i--)for(j=0;j<2;j++)for(k=0;k<2;k++)for(l=0;l<=m;l++)
		{
			if(i==n&&!l&&n!=1||k&&l>a[i-1])continue;
			if(i-1!=(m>>2)||((l>>(m&3))&1))f[i-1][j|(l==m)][k&(l==a[i-1])]+=f[i][j][k];
		}
		s+=f[0][1][0];
	}
	return s;
}
int main()
{
	for(n=1;n<16;n++)for(m=0;m<16&&m<(n<<2);m++)
	{
		g[n][m][n][0]=1;
		for(i=n;i;i--)for(j=0;j<2;j++)for(k=0;k<=m;k++)
		{
			if(i==n&&!k&&n!=1)continue;
			if(i-1!=(m>>2)||((k>>(m&3))&1))g[n][m][i-1][j|(k==m)]+=g[n][m][i][j];
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s1,s2);
		n1=strlen(s1);
		n2=strlen(s2);
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		for(i=0;i<n1;i++)if(s1[i]<'a')a1[i]=s1[i]-'0';
		else a1[i]=s1[i]-'a'+10;
		for(i=0;i<n2;i++)if(s2[i]<'a')a2[i]=s2[i]-'0';
		else a2[i]=s2[i]-'a'+10;
		reverse(a2,a2+n2);
		a2[0]++;
		for(i=0;i<n2&&a2[i]==16;i++)
		{
			a2[i+1]++;
			a2[i]=0;
		}
		if(a2[n2])n2++;
		ans=work(n2,a2);
		reverse(a1,a1+n1);
		ans-=work(n1,a1);
		cout<<ans<<endl;
	}
	return 0;
}