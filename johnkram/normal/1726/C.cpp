#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int t,n,m,i,s[MAXN],top,ne[MAXN];
char c[MAXN];
int work(int l,int r)
{
	if(l>r)return 0;
	int i,s=1;
	for(i=l;i<=r;i=ne[i]+1)s+=work(i+1,ne[i]-1);
	return s;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,c+1);
		top=0;
		for(i=1;i<=n<<1;i++)if(c[i]=='(')s[++top]=i;
		else ne[s[top--]]=i;
		printf("%d\n",work(1,n<<1));
	}
	return 0;
}