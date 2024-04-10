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

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn];
int t1,t2;
vector <int> ans;

int main()
{
	int n=read(); scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='B') t1++;
		else t2++;
	}
	if(n%2==0&&t1%2==1) {puts("-1"); return 0;}
	if(t1%2==0)
	{
		for(int i=1;i+1<=n;i++)
		{
			if(s[i]=='B')
			{
				ans.push_back(i);
				if(s[i+1]=='W') s[i+1]='B';
				else s[i+1]='W';
			}
		}
	}
	else
	{
		for(int i=1;i+1<=n;i++)
		{
			if(s[i]=='W')
			{
				ans.push_back(i);
				if(s[i+1]=='W') s[i+1]='B';
				else s[i+1]='W';
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}