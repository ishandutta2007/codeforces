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

struct node{string s;int len;}a[maxn];
int n;

inline bool cmp(node a,node b)
{
	return a.len<b.len;
}

inline bool jud(int x,int y)
{
	for(int i=0;i<a[y].len-a[x].len+1;i++)
	{
		bool flag=0; int cnt=0;
		for(int j=0;j<a[x].len;j++)
		{
			if(a[y].s[i+cnt]!=a[x].s[cnt++])
			{
				flag=1;
				break;
			}
		}
		if(flag==0) return true;
	}
	return false;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].s,a[i].len=a[i].s.length();
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		if(jud(i-1,i)) continue;
		else {puts("NO"); return 0;}
	}
	puts("YES");
	for(int i=1;i<=n;i++) cout<<a[i].s<<endl;
	return 0;
}