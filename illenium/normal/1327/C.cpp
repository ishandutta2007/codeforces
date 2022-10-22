#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

vector <char> v;
int n,m,k;

int main()
{
	n=read(); m=read(); k=read();
	for(int i=1;i<=n-1;i++) v.push_back('U');
	for(int i=1;i<=m-1;i++) v.push_back('L');
	for(int i=1;i<=n;i++)
	{
		if(i%2==1) for(int j=1;j<=m-1;j++) v.push_back('R');
		else for(int j=1;j<=m-1;j++) v.push_back('L');
		if(i!=n) v.push_back('D');
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++) printf("%c",v[i]); puts("");
	return 0;
}