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

vector <int> ans;
map <int,int> mp;

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),tmp=sqrt(n); ans.push_back(0);
		for(int i=1;i<=tmp;i++) ans.push_back(i),mp[i]=1;
		for(int i=tmp;i>=1;i--)
		{
			if(mp[n/i]==1) continue;
			ans.push_back(n/i); mp[n/i]=1;
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]); puts("");
		mp.clear(); ans.clear();
	}
	return 0;
}