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

multiset <int> s;
multiset <int>::iterator it;
int a[maxn],b[maxn],c[maxn],n;

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n-1;i++) b[i]=read();
	for(int i=1;i<=n-2;i++) c[i]=read();
	for(int i=1;i<=n;i++) s.insert(a[i]);
	for(int i=1;i<=n-1;i++) it=s.find(b[i]),s.erase(it);
	it=s.begin(); cout<<*it<<endl; s.clear();
	for(int i=1;i<=n-1;i++) s.insert(b[i]);
	for(int i=1;i<=n-2;i++) it=s.find(c[i]),s.erase(it);
	it=s.begin(); cout<<*it<<endl;
	return 0;
}