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

int n,p,a[maxn];
ll tot,tot1,tot2;

int main()
{
	cin>>n; int p=n/2;
	for(int i=1;i<=p;i++) a[i]=read();
	sort(a+1,a+p+1); int cnt=0;
	for(int i=1;i<=n;i+=2) tot1+=abs(a[++cnt]-i); cnt=0;
	for(int i=2;i<=n;i+=2) tot2+=abs(a[++cnt]-i);
	cout<<min(tot1,tot2);
	return 0;
}