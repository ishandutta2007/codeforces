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
vector <int> ans;
bool vis[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;i++) vis[i]=0; ans.clear();
		for(int i=1;i+4<=len;i++)
		{
			if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]=='e')
				ans.push_back(i+2),vis[i]=1,vis[i+1]=1,vis[i+2]=1,vis[i+3]=1,vis[i+4]=1,i+=4;
		}
		for(int i=1;i+2<=len;i++)
		{
			if(vis[i]) continue;
			if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o') ans.push_back(i+1);
			if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e') ans.push_back(i+1);
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]); puts("");
	}
	return 0;
}