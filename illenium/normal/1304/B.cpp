#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

string s[105];
map <string,int> p;
string ans,p1;

int main()
{
	int n=read(),m=read(),f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		p[s[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		string tmp="";
		for(int j=m-1;j>=0;j--) tmp+=s[i][j]; //cout<<tmp<<endl;
		if(tmp==s[i])
		{
			if(f==0&&p[tmp]%2==1)
			{
				f=1; p[tmp]--;
				p1=tmp;
			}
			else if(p[tmp]>=2)
			{
				p[tmp]-=2;
				ans+=p[tmp];
			}
		}
		else
		{
			if(p[tmp]!=0)
			{
				p[tmp]--; p[s[i]]--;
				ans+=s[i];
			}
		}
	}
	int len=ans.length()*2+p1.length();
	cout<<len<<endl;
	cout<<ans<<p1;
	for(int i=ans.length()-1;i>=0;i--) printf("%c",ans[i]);
	return 0;
}