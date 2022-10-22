#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
char c[30];
string s[1005],ans[1005];
bool b[1005][1005],v[1005];
int n,i,j,k;
void dfs(int x)
{
	v[x]=1;
	for(int i=0;i<n;i++)if(!v[i]&&b[x][i])dfs(i);
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",c);
		for(j=0;j<3;j++)s[i]+=c[j];
		scanf("%s",c);
		s[i]+=c[0];
	}
	for(i=0;i<n;i++)for(j=0;j<n;j++)if(i!=j&&s[i][0]==s[j][0]&&s[i][1]==s[j][1]&&s[i][3]==s[j][2])b[i][j]=1;
	for(i=0;i<n;i++)if(!v[i])
	{
		for(j=i+1;j<n;j++)if(!v[j]&&s[i][0]==s[j][0]&&s[i][1]==s[j][1]&&s[i][2]==s[j][2])break;
		if(j<n)for(dfs(i);j<n;j++)if(!v[j]&&s[i][0]==s[j][0]&&s[i][1]==s[j][1]&&s[i][2]==s[j][2])dfs(j);
	}
	for(i=0;i<n;i++)
	{
		ans[i]+=s[i][0];
		ans[i]+=s[i][1];
		ans[i]+=s[i][2|v[i]];
	}
	for(i=0;i<n;i++)for(j=i+1;j<n;j++)if(ans[i]==ans[j])goto xxx;
	xxx:if(i<n)puts("NO");
	else for(puts("YES"),i=0;i<n;i++)cout<<ans[i]<<endl;
	return 0;
}