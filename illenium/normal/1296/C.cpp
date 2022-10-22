#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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
struct node{int a,b;};

inline bool operator <(node a,node b)
{
	if(a.a!=b.a) return a.a<b.a;
	return a.b<b.b;
}

map <node,int> p;

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),f1=0,f2=0; scanf("%s",s+1); p.clear();
		int a=0,b=0,ans=inf; p[(node){0,0}]=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='L') a++;
			else if(s[i]=='R') a--;
			else if(s[i]=='U') b++;
			else if(s[i]=='D') b--;
			//cout<<a<<" "<<b<<endl;
			if(p[(node){a,b}])
			{
				if(ans>i-p[(node){a,b}])
					ans=i-p[(node){a,b}],f1=p[(node){a,b}],f2=i;
				p[(node){a,b}]=i+1;
			}
			else p[(node){a,b}]=i+1;
		}
		if(ans==inf) puts("-1");
		else printf("%d %d\n",f1,f2);
	}
	return 0;
}