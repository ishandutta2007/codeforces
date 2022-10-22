#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

int n,d,ans=20;
int a[15],b[15];

inline bool judge()
{
	int p=0;
	for(int i=d;i>=1;i--)
	{
		if(b[i]==1) continue;
		if(b[i]==0&&a[i]==0) return false;
		break;
	}
	for(int i=d;i>=1;i--)
	{
		if(b[i]==0) p=p*10+a[i];
	}
	if(p==0) return false;
	if(sqrt(p)==floor(sqrt(p)))
	{
		return true;
	}
	return false;
}

inline int cal()
{
	int tmp=0;
	for(int i=1;i<=d;i++) tmp+=b[i];
	return tmp;
}

void dfs(int u)
{
	if(u==d+1)
	{
		if(judge())
		{
			//for(int i=d;i>=1;i--) cout<<b[i]<<" "; cout<<endl;
			ans=min(ans,cal());
		}
		return;
	}
	for(int i=0;i<=1;i++)
	{
		b[u]=i;
		dfs(u+1);
	}
}

int main()
{
	cin>>n;
	int tmp=n;
	while(tmp)
	{
		a[++d]=tmp%10;
		tmp/=10;
	}
	dfs(1);
	if(ans==20) cout<<"-1";
	else cout<<ans;
	return 0;
}