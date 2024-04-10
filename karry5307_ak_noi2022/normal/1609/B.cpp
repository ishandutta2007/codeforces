#include<cstdio>

using namespace std;

char s[200000];

int main()
{
	int n=0,q=0;scanf("%d%d%s",&n,&q,s+1);
	int ans=0;for(int i=1;i<=n-2;i++)if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')ans++;
	while(q--)
	{
		int pos=0;char ch='\0';scanf("%d %c",&pos,&ch);
		if(s[pos]=='a')
		{
			if(pos<=n-2&&s[pos+1]=='b'&&s[pos+2]=='c')ans--;
		}
		else if(s[pos]=='b')
		{
			if(pos<=n-1&&pos>=2&&s[pos+1]=='c'&&s[pos-1]=='a')ans--;
		}
		else
		{
			if(pos>=3&&s[pos-1]=='b'&&s[pos-2]=='a')ans--;
		}
		s[pos]=ch;
		if(s[pos]=='a')
		{
			if(pos<=n-2&&s[pos+1]=='b'&&s[pos+2]=='c')ans++;
		}
		else if(s[pos]=='b')
		{
			if(pos<=n-1&&pos>=2&&s[pos+1]=='c'&&s[pos-1]=='a')ans++;
		}
		else
		{
			if(pos>=3&&s[pos-1]=='b'&&s[pos-2]=='a')ans++;
		}
		printf("%d\n",ans);
	}
}