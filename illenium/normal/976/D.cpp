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

int n,a[maxn],v,m,k,l,r,f[maxn];
vector <int> x,y;

int main()
{
	//freopen("CF976D.in","r",stdin);
	int n=read(); for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) f[a[i]]=1;
	while(a[n]>r)
	{
		do
		{
			for(int i=l+2;i<=a[n]+1;i++) x.push_back(l+1),y.push_back(i);
			l++; r++;
		}while(!f[r]);
		n--;
	}
	cout<<x.size()<<endl;
	for(int i=0;i<x.size();i++) printf("%d %d\n",x[i],y[i]);
	return 0;
}