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

ll n,k,a[maxn],tmp,p;
map <ll,int> mp;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) mp[a[i]]++;
	int tot=unique(a+1,a+n+1)-a-1;
	for(int i=2;i<=tot;i++) if(a[i]>a[i-1]&&a[i]<=a[i-1]+k) tmp+=mp[a[i-1]];
	cout<<n-tmp<<endl;
	return 0;
}