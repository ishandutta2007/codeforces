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

int n,a[maxn],ans;
map <int,int> mp;

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) mp[a[i]]++;
	int l1=1,l2=2;
	while(l1<=n)
	{
		while(a[l2]==a[l1]) l2++;
		if(l2==n+1) break;
		ans++; l1++; l2++;
		if(l2==n+1) break;
	}
	cout<<ans<<endl;
	return 0;
}