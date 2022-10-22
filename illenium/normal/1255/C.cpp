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

struct node{int id,a,b,c;};
vector <node> vec[maxn];
vector <int> ans;
bool vis[maxn];
queue <int> que;
int cnt[maxn],cnt2[maxn];

int main()
{
	int n=read();
	for(int i=1;i<=n-2;i++)
	{
		int a=read(),b=read(),c=read();
		cnt[a]++; cnt[b]++; cnt[c]++;
		vec[a].push_back((node){i,a,b,c});
		vec[b].push_back((node){i,a,b,c});
		vec[c].push_back((node){i,a,b,c});
	}
	for(int i=1;i<=n;i++) cnt2[i]=cnt[i];
	int f=0;
	for(int i=1;i<=n;i++) if(cnt[i]==1) {f=i; break;}
	que.push(f);
	while(!que.empty())
	{
		int u=que.front(); que.pop(); ans.push_back(u);
		for(int j=0;j<vec[u].size();j++)
		{
			node tmp=vec[u][j];
			if(vis[tmp.id]) continue;
			vis[tmp.id]=1;
			if(cnt[tmp.a]==1&&cnt[tmp.b]==1&&cnt[tmp.c]==1)
			{
				if(cnt2[tmp.a]==2) ans.push_back(tmp.a);
				if(cnt2[tmp.b]==2) ans.push_back(tmp.b);
				if(cnt2[tmp.c]==2) ans.push_back(tmp.c);
				if(cnt2[tmp.a]==1) ans.push_back(tmp.a);
				if(cnt2[tmp.b]==1) ans.push_back(tmp.b);
				if(cnt2[tmp.c]==1) ans.push_back(tmp.c);
			}
			if(cnt[tmp.a]+cnt[tmp.b]+cnt[tmp.c]==5)
			{
				if(cnt[tmp.a]==2&&cnt2[tmp.a]==3) que.push(tmp.a);
				if(cnt[tmp.b]==2&&cnt2[tmp.b]==3) que.push(tmp.b);
				if(cnt[tmp.c]==2&&cnt2[tmp.c]==3) que.push(tmp.c);
				cnt[tmp.a]--; cnt[tmp.b]--; cnt[tmp.c]--;
			}
			else
			{
				cnt[tmp.a]--; cnt[tmp.b]--; cnt[tmp.c]--;
				if(cnt[tmp.a]==1) que.push(tmp.a);
				if(cnt[tmp.b]==1) que.push(tmp.b);
				if(cnt[tmp.c]==1) que.push(tmp.c);
			}
			
		}
	}
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}