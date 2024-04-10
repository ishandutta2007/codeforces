#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n;

int main()
{
	n=read();
	cout<<3*(n+1)+1<<endl;
	for(int i=0;i<=n+1;i++) printf("%d %d\n",i,i);
	for(int i=0;i<=n;i++) printf("%d %d\n%d %d\n",i+1,i,i,i+1);
	return 0;
}