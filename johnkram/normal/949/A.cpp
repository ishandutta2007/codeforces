#include<bits/stdc++.h>
using namespace std;
queue<int> q1,q2;
char c[200005];
int n,i,d[200005],a[200005];
void out(int x)
{
	if(!x)return;
	out(a[x]);
	printf(" %d",x);
}
int main()
{
	scanf("%s",c+1);
	n=strlen(c+1);
	for(i=1;i<=n;i++)if(c[i]=='0')
	{
		if(q2.empty())d[i]=1;
		else
		{
			a[i]=q2.front();
			d[i]=d[q2.front()]+1;
			q2.pop();
		}
		q1.push(i);
	}
	else if(q1.empty())
	{
		puts("-1");
		return 0;
	}
	else
	{
		a[i]=q1.front();
		d[i]=d[q1.front()]+1;
		q1.pop();
		q2.push(i);
	}
	if(!q2.empty())
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",q1.size());
	while(!q1.empty())
	{
		printf("%d",d[q1.front()]);
		out(q1.front());
		puts("");
		q1.pop();
	}
	return 0;
}