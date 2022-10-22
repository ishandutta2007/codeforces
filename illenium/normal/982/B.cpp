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
#define maxn 500005
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

int n;
string s;
struct node{int w,id;}p[maxn];
priority_queue <node> que;

inline bool operator<(node x,node y)
{
	return x.w<y.w;
}

inline bool cmp(node x,node y)
{
	return x.w<y.w;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) p[i].w=read(),p[i].id=i;
	cin>>s;
	sort(p+1,p+n+1,cmp);
	int l=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')
		{
			l++;
			cout<<p[l].id<<" ";
			que.push(node{p[l].w,p[l].id});
		}
		else
		{
			node u=que.top(); que.pop();
			cout<<u.id<<" ";
		}
	}
	return 0;
}