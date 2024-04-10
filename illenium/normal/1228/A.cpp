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

int ans,l,r;

inline bool ch(int x)
{
	map <int,int> p;
	p.clear();
	while(x!=0)
	{
		int a=x%10;
		p[a]++;
		if(p[a]==2) return 0;
		x/=10;
	}
	return 1;
}

int main()
{
	cin>>l>>r;
	int flag=0;
	for(int i=l;i<=r;i++) if(ch(i))
	{
		cout<<i<<endl;
		flag=1;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}