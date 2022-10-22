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

int p[maxn];
int s1,s2;
ll ans1,ans2;

int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(x>0) p[i]=1;
		else p[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==1)
		{
			s1++;
			ans1+=s1;
			ans2+=s2;
		}
		else
		{
			swap(s1,s2); s2++;
			ans1+=s1;
			ans2+=s2;
		}
	}
	cout<<ans2<<" "<<ans1<<endl;
	return 0;
}