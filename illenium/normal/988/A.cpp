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

int n,k,a[maxn],b[maxn],tot,cnt;
bool vis[maxn];

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	tot=unique(b+1,b+n+1)-b-1;
	if(tot<k) {puts("NO"); return 0;}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]]==0)
		{
			printf("%d ",i);
			vis[a[i]]=1; cnt++;
		}
		if(cnt==k) return 0;
	}
	return 0;
}