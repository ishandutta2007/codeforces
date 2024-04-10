#include<bits/stdc++.h>

using namespace std;

struct trie
{
	struct trienode
	{
		int ch[2],sz;
	}tr[10000005];
	int cnt;
	
	void insert(int x,int y)
	{
		vector<int> dig;
		
		int i;
		for (i=0;i<31;i++)
		{
			dig.push_back(x%2);
			x/=2;
		}
		reverse(dig.begin(),dig.end());
		
		int cur=1;
		tr[1].sz+=y;
		
		for (i=0;i<31;i++)
		{
			if (!tr[cur].ch[dig[i]]) tr[cur].ch[dig[i]]=++cnt;
			cur=tr[cur].ch[dig[i]];
			
			tr[cur].sz+=y;
		}
	}
	
	int query(int x)
	{
		vector<int> dig;
		
		int i;
		for (i=0;i<31;i++)
		{
			dig.push_back(x%2);
			x/=2;
		}
		reverse(dig.begin(),dig.end());
		
		int cur=1,ans=0;
		
		for (i=0;i<31;i++)
		{
			ans<<=1;
			
			if ((!tr[cur].ch[dig[i]])||(!tr[tr[cur].ch[dig[i]]].sz))
			{
				cur=tr[cur].ch[!dig[i]];
				ans+=!dig[i];
			}
			else
			{
				cur=tr[cur].ch[dig[i]];
				ans+=dig[i];
			}
		}
		
		return ans;
	}
}tr;

int a[333333];

int main()
{
	tr.cnt=1;
	int n,i,x;
	
	scanf("%d",&n);
	
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		
		tr.insert(x,1);
	}
	
	for (i=1;i<=n;i++)
	{
		int t=tr.query(a[i]);
		
		//fprintf(stderr,"\n%d\n",t);
		
		printf("%d ",a[i]^t);
		
		tr.insert(t,-1);
	}
	
	return 0;
}