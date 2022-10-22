#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
#define MAXN 100005
#define ll long long
map<int,int> s;
priority_queue<int> h;
int n,i,j,a[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		s[a[i]]=1;
		h.push(a[i]);
	}
	for(n=0;!h.empty();)
	{
		i=h.top();
		h.pop();
		s[i]=0;
		for(j=i>>1;j&&s[j];j>>=1);
		if(j)
		{
			h.push(j);
			s[j]=1;
		}
		else a[++n]=i;
	}
	for(i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}