#include <bits\stdc++.h>

using namespace std;

int ans[125555],nxt[125555],ss[125555],st[125555],mp[6];
string s,t;
int ls,lt;

void getnxt()
{
	int i,j=0;
	
	for (i=2;i<=ls;i++)
	{
		while (j>=1&&st[i]!=st[j+1]) j=nxt[j];
		
		if (st[i]==st[j+1])
		{
			j++;
		}
		
		nxt[i]=j;
		
	}
	
}

void kmp(int y)
{
	int i,j=0;
	
	st[lt+1]=66666;
	
	for (i=1;i<=ls;i++)
	{
		while (j>=1&&ss[i]!=st[j+1])
		{
			j=nxt[j];
		}
		
		if (ss[i]==st[j+1])
		{
			j++;
		}
		
		if (j==lt) ans[i-lt+1]=min(ans[i-lt+1],y);
		
	}
	
}

void getans(int y)
{
	int i,j;
	
	for (i=1;i<=ls;i++)
	{
		ss[i]=mp[s[i]-'a'];
	}
	
	for (i=1;i<=lt;i++)
	{
		st[i]=mp[t[i]-'a'];
	}
	
	getnxt();
	kmp(6-y);
	
}

void dfs(char x,int y)
{
	if (x>'f')
	{
		getans(y);
		return;
	}
	
	int i;
	
	for (i=1;i<=y+1;i++)
	{
		mp[x-'a']=i;
		dfs(x+1,max(i,y));
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	memset(ans,0x3f,sizeof(ans));
	
	cin>>s>>t;
	
	ls=s.size();
	lt=t.size();
	
	s=" "+s;
	t=" "+t;
	
	dfs('a',0);
	
	for (int i=1;i<=ls-lt+1;i++) cout<<ans[i]<<(i==ls-lt+1?'\n':' ');
	
	return 0;
	
}