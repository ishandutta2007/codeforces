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
 
vector <int> v1,v2;
bool vis[maxn];
int a[maxn];
 
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==0) v1.push_back(i);
		else vis[a[i]]=1;
	}
	for(int i=1;i<=n;i++) if(vis[i]==0) v2.push_back(i);
	random_shuffle(v1.begin(),v1.end());
	random_shuffle(v2.begin(),v2.end());
	for(int i=0;i<v1.size()-2;i++)
	{
		if(v1[i]==v2[i]) swap(v1[i],v1[i+1]);
		a[v1[i]]=v2[i];
	}
	if(v1[v1.size()-1]!=v2[v1.size()-1])
		a[v1[v1.size()-1]]=v2[v1.size()-1],a[v1[v1.size()-2]]=v2[v1.size()-2];
	else a[v1[v1.size()-1]]=v2[v1.size()-2],a[v1[v1.size()-2]]=v2[v1.size()-1];
	for(int i=0;i<v1.size()-1;i++) if(a[v1[i]]==v1[i]) swap(a[v1[i]],a[v1[i+1]]);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}