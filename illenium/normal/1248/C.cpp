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
#define modc 1000000007
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,f[maxn];

int main()
{
	cin>>n>>m;
	f[1]=2; f[2]=4;
	for(int i=3;i<=max(n,m);i++) f[i]=(f[i-1]+f[i-2])%modc;
	cout<<(f[n]+f[m]-2)%modc;
	return 0;
}