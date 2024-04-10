#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define inf 1e9
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

int minn=inf,ans=inf;
int a[100005];
vector <int> v;

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read(),minn=min(minn,a[i]);
	for(int i=1;i<=n;i++) if(a[i]==minn) v.push_back(i);
	for(int i=1;i<v.size();i++) ans=min(ans,v[i]-v[i-1]);
	cout<<ans<<endl;
	return 0;
}