#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
char c[MAXN];
int t,n,q,i,j,a[MAXN],b[MAXN],s[MAXN][2];
int main()
{
	scanf("%d%d%s",&n,&q,c+1);
	for(i=1;i<n;i++)
	{
		copy(s[i-1],s[i-1]+2,s[i]);
		if(c[i]==c[i+1])s[i][c[i]^'0']++;
	}
	while(q--)
	{
		scanf("%d%d",&i,&j);
		i--;
		j--;
		printf("%d\n",max(s[j][0]-s[i][0],s[j][1]-s[i][1])+1);
	}
	return 0;
}