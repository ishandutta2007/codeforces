#include<bits/stdc++.h>
#define ll long long
#define inf 0x7f7f7f7f
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n;
int a[105];
int vis[105];
int sum; 
int ans;
vector<int> g[105];
int cur[105];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{ a[i]=read();sum+=a[i];g[a[i]].push_back(i); }
	sum/=(n/2);
	for(int i=1;i<=100;i++) cur[i]=g[i].size()-1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			printf("%d %d\n",i,g[sum-a[i]][cur[sum-a[i]]]);
			vis[g[sum-a[i]][cur[sum-a[i]]]]=1;cur[sum-a[i]]--;
		}
	}
	return 0;
}