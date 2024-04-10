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

int a1,a2,k1,k2,n;

int main()
{
	cin>>a1>>a2>>k1>>k2>>n;
	if(k1>k2)
	{
		swap(k1,k2);
		swap(a1,a2);
	}
	int x1=a1*k1,x2=a2*k2;
	int tot=x1+x2-a1-a2;
	cout<<max(n-tot,0)<<" ";
	if(n<=x1) cout<<n/k1;
	else cout<<a1+min((n-x1)/k2,a2)<<" ";
	return 0;
}