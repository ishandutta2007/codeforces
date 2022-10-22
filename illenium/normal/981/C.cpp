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

int mx,ans,ind[maxn],flag;
vector <int> vec;

int main()
{
	int n=read();
	if(n==2) {puts("Yes"); cout<<"1"<<endl; puts("1 2"); return 0;}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ind[v]++; ind[u]++;
	}
	for(int i=1;i<=n;i++) if(ind[i]>=mx) flag=i,mx=ind[i];
	for(int i=1;i<=n;i++) if(ind[i]>2) ans++;
	if(ans>=2) {puts("No"); return 0;}
	puts("Yes");
	for(int i=1;i<=n;i++) if(ind[i]==1) vec.push_back(i);
	cout<<vec.size()<<endl;
	for(int i=0;i<vec.size();i++) printf("%d %d\n",flag,vec[i]);
	return 0;
}