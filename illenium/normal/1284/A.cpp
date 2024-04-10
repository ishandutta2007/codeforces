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

string s1[maxn],s2[maxn];

int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++) cin>>s1[i]; s1[0]=s1[n];
	for(int i=1;i<=m;i++) cin>>s2[i]; s2[0]=s2[m];
	int q=read();
	while(q--)
	{
		int x=read();
		cout<<s1[x%n]<<s2[x%m]<<endl;
	}
	return 0;
}